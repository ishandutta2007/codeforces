#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 998244353;

ll n,k;
int h[222222];

ll f[222222];
ll k2[222222];
ll invf[222222];

ll p2[222222];

ll c(int n,int m){
	return f[n]*invf[m]%mod*invf[n-m]%mod;
}

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	string s;
	cin>>tc;
	REP(TC,tc){
		cin>>s;
		vi r;
		for(int i=0;i<int(s.size())-2;i++){
			if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
				if(i+4<s.size() && s[i+3]=='n' && s[i+4]=='e'){
					r.pb(i+2);
					i += 3;
				}else{
					r.pb(i+1);
				}
			}else if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
				r.pb(i+1);
			}
		}
		cout<<r.size()<<endl;
		REP(i,r.size()) printf("%d ",r[i]+1);
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}