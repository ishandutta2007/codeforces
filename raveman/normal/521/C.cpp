#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const ll mod = 1000000000+7;

int n,k;
string s;


ll f[222222];
ll invf[222222];


ll c(int n,int m){
	if(n<0 || m<0 || m>n) return 0;
	ll res = f[n];
	res *= invf[m]; res %= mod;
	res *= invf[n-m]; res %= mod;
	return res;
}


ll qp(ll c,ll st){
	ll r = 1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

ll v[111111];

int solve(int n,int k){
	return c(n,k);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,222222)f[i]=(f[i-1]*i)%mod;
	REP(i,222222)invf[i]=qp(f[i],mod-2);


	cin>>n>>k>>s;
	ll res = 0;

	if(k==0){
		REP(i,s.size()) res = res * 10 + s[i]-'0',res%=mod;
	}else{	
		REP(i,111111){
			v[i]=solve(n-2-i,k-1)*qp(10,i)%mod;
			if(i) v[i]+=v[i-1],v[i]%=mod;
		}
		REP(i,s.size()){
			ll val = (s[i]-'0')*qp(10,n-1-i)%mod;
			val *= solve(i,k); val %= mod;

			if(n-2-i>=0){
				val = ( val + (s[i]-'0')*v[n-2-i])%mod;
			}

			res += val; res %= mod;
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}