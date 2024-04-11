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

	cin>>n>>k;

	if(k==1){
		cout<<0<<endl;
		return 0;
	}

	f[0]=1;
	FOR(i,1,222222)f[i]=f[i-1]*i%mod;
	k2[0]=1;
	FOR(i,1,222222)k2[i]=k2[i-1]*(k-2)%mod;
	p2[0]=1;
	FOR(i,1,222222)p2[i]=p2[i-1]*2%mod;

	REP(i,222222)invf[i]=qp(f[i],mod-2);
	ll inv2 = qp(2,mod-2);

	REP(i,n)scanf("%d",h+i);
	int m=0;
	REP(i,n)if(h[i]!=h[(i+1)%n])m++;

	ll res = 0;
	REP(ij,m+1){
		ll hf = p2[ij];
		if(ij%2==0){
			hf -= c(ij,ij/2);
			if(hf<0)hf+=mod;
		}
		hf *= inv2; hf%=mod;
		ll t = c(m,ij);
		t *= k2[m-ij]; t %= mod;
		t *= hf; t %= mod;

		res += t;
		res %= mod;
	}
	REP(i,n-m)res*=k,res%=mod;
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}