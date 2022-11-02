#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;	 
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

ll p[22];
ll f(ll n){
	stringstream ss;
	ss<<n;
	string s = ss.str();
	ll res =  0;
	FOR(i,1,s.size()){
		int len = i;
		len -= 2;
		if(len<0) len = 0;
		res += p[len]*9;
	}
	string t = s;
	FOR(i,1,10){
		if(s[0]-'0' < i) break;
		if(s[0]-'0' == i){
			ll val = 0;
			FOR(j,1,s.size()-1) val = 10 * val + s[j]-'0';
			val ++;
			if(s[s.size()-1]-'0' < i) val--;
			res += val;
		}else res += p[max(0,(int)s.size()-2)];
	}
	return res;
}

bool good(ll n){
	stringstream ss;
	ss<<n;
	string s = ss.str();
	return s[0]==s[s.size()-1];
}
ll stupid(ll l,ll r){
	ll res = 0;
	for(ll i = l;i<=r;i++)
		if(good(i)) res++;
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	p[0]=1;
	FOR(i,1,20) p[i]=p[i-1]*10;
	ll l,r;
	cin>>l>>r;
	if(l>r) swap(l,r);
	cout<<f(r)-f(l-1)<<endl;
//	cout<<f(r)<<' '<<f(l-1)<<endl;
//	cout<<stupid(l,r)<<endl;
	//if(f(r)-f(l-1)==stupid(l,r)) goto start;

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}