#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

char c[22];
int pos;



const int mod = 504;
int per[mod][10];
ll   r[20][2][mod][4][3][2][2];

ll go(ll n){
	pos = 0;
	while(n){
		c[pos] = char('0'+(n%10));
		n/=10;
		pos++;
	}
	reverse(c,c+pos);
	CL(r,0);
	r[0][0][0][0][0][0][0]=1;
	REP(i, pos) REP(fl, 2) REP(ost, mod) REP(two, 4) REP(three, 3) REP(five, 2) REP(seven, 2){
		int to = fl ? 10 : (c[i] -'0' + 1);
		ll val = r[i][fl][ost][two][three][five][seven];
		if(!val) continue;
		if(fl==0)
			fl=fl;
		REP(dig, to){
			if(five && i==pos-1 && dig!=5 && dig!=0) continue;
			int tw =  (dig == 8 ? 3 : (dig == 4 ? 2 : ((dig%2)==0 && dig ? 1: 0)));
			int th = (dig == 9 ? 2 : ((dig%3)==0 && dig ? 1 : 0));
			r[i+1][fl|(dig<to-1)][per[ost][dig]][max(two,tw)][max(three,th)][five|(dig==5)][seven|(dig==7)]+=val;
		}
	}
	ll sum = 0;
	REP(fl, 2) REP(ost, mod) REP(two, 4) REP(three, 3) REP(five, 2) REP(seven, 2){
		if(seven && (ost%7)) continue;
		if(three == 1 && (ost%3)) continue;
		if(three == 2 && (ost%9)) continue;
		if(two == 1 && (ost%2)) continue;
		if(two == 2 && (ost%4)) continue;
		if(two == 3 && (ost%8)) continue;
		sum += r[pos][fl][ost][two][three][five][seven];
	}
	return sum;
}

ll f(ll n){
	if(n==0) return 1;
	return go(n);
}


bool good(ll x){
	ll y=x;
	while(y){
		int c = y%10;
		y/=10;
		if(c && (x%c)) return 0;
	}
	return 1;
}

ll stupid(ll a,ll b){
	ll res =0;
	for(ll i=a;i<=b;i++)
		if(good(i)) res++;
	return res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	REP(ost,mod) REP(dig,10)
		per[ost][dig] = (ost*10+dig)%mod;
	int tc;
	cin>>tc;
	REP(TC,tc){
		ll x, y;
		cin>>x>>y;
		
		cout<<f(y) - f(x-1)<<endl;
		//cout<<stupid(x,y)<<endl;
	}
    return 0;
}