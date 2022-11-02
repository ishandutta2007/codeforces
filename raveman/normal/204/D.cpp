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
typedef unsigned long ull;

typedef vector<int> vi;	 
typedef pair<int,int> pii;
typedef pair<double,double> pdd;


#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int mod = 1000000007;

int n,k;
char s[1111111];
char t[1111111];
vi v1,v2;

int sum[1111111];
vi tmp;

int tp[1111111];
int w[1111111];
int q[1111111];
int sw[1111111];

vi solve(char *s){
	tmp.clear();
	tmp.resize(n, 0);
	CL(w,0);CL(sw,0);CL(q,0);
	int num = 0;
	int lastw = -1;
	REP(i,n){
		if(s[i]=='X') q[i]=1;
		if(i) q[i]+=q[i-1];
		if(s[i]=='B' || s[i]=='X') num++;
		else num = 0;

		if(num>=k){
			int pos = i - k;
			if(pos<0) tmp[i] = 1;
			else  tmp[i] = w[pos];
		}

		w[i] = 0;
		if(s[i]=='W' || s[i]=='X'){
			if(i==0) w[i] = 1;
			else {
				if(i-1-k<-1){
					w[i] = tp[q[i-1]];
				}else{
					int pos = i-1-k;
					if(lastw>pos) pos = lastw-1;
					w[i] += sw[i-1] - (pos>=0?sw[pos]:0);
				}
				w[i]%=mod;
				if(w[i]<0) w[i]+=mod;
			}
		}
		
		sw[i] = w[i];
		if(i) sw[i]+=sw[i-1],sw[i]%=mod;
		
	//	cout<<i<<" -> w[i] "<<w[i]<<"   sw[i] "<<sw[i]<<"  tmp "<<tmp[i]<<endl;
		if(s[i]=='W') lastw=i;
	}
	
	return tmp;
}

int go(string z, int pos){
	if(pos==z.size()){
		int num=0;
		REP(i,n){
			if(z[i]=='B') num++;
			else num = 0;
			if(num==k){
				num=0;
				FOR(j,i,n){
					if(z[j]=='W') num++;
					else num=0;
					if(num==k) return 1;
				}
				break;
			}			
		}
		return 0;
	}
	int res = 0;
	if(z[pos]=='X'){
		string t1 = z;
		t1[pos]='B';
		res += go(t1, pos+1);
		t1[pos]='W';
		res += go(t1, pos+1);
		return res;
	}
	return go(z,pos+1);
}
int num(){
	string z = s;
	return go(z, 0);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	tp[0]= 1;
	FOR(i,1,1111111) tp[i]=(tp[i-1]*2)%mod;
	cin>>n>>k;

	scanf(" %s",s);
	
	v1 = solve(s);
	//REP(i,v1.size()) cout<<v1[i]<<' ';puts("");

	REP(i,n) t[i] = s[n-1-i];
	REP(i,n) if(t[i]=='W') t[i]='B';
	else if(t[i]=='B') t[i]='W';
	v2 = solve(t);
	reverse(v2.begin(),v2.end());
	//REP(i,v2.size()) cout<<v2[i]<<' ';puts("");

	ll res = 0;
	REP(i,v1.size()){
		sum[i] = v1[i];
		if(i){
			int add = sum[i-1];
			if(s[i]=='X') add*=2,add%=mod;
			sum[i] += add;
			sum[i] %= mod;
		}
	}
	//REP(i,v1.size()) cout<<i<<' '<<sum[i]<<endl;

	

	FOR(i,1,v2.size())if(v2[i]){
		res += v2[i] * ll(sum[i-1]);
		//cout<<"add "<<i<<' '<<v2[i]<<" "<< ll(sum[i-1])<<endl;
		res %= mod;
	}
//	cout<<res<<' '<<num()<<endl;
	cout<<res<<endl;
	
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}