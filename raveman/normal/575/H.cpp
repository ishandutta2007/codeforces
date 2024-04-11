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

const int mod = 1000000000+7;

ll st[2111111];
ll  f[2111111];

ll qp(ll c, ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

ll c(int n,int m){
	ll res = f[n];
	res *= qp(f[m]*f[n-m]%mod,mod-2);
	res %= mod;
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	st[0]=f[0]=1;
	FOR(i,1,2111111){
		st[i]=st[i-1]*2;if(st[i]>=mod)st[i]-=mod;
		f[i]=(f[i-1]*i)%mod;
	}


	int n;
	cin>>n;
	ll res = 0;
	REP(i,2*n+1){
		res = (res + st[i]);if(res>=mod)res-=mod;		
	}
	for(int len=n+1;len<=2*n;len++){
		res = (res - c(len-1,n) * (st[2*n-len+1]-1)%mod*2%mod);
		if(res<0)res+=mod;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}