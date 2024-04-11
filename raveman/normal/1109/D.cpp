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

const int mod = 1000000007;

ll mp[1<<20];
ll np[1<<20];
ll  f[1<<20];
ll fi[1<<20];

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1){
			r*=c;
			r%=mod;
		}
		st>>=1;
		c*=c;c%=mod;
	}
	return r;
}

ll c(int n,int m){
	if(m>n || m<0) return 0;
	if(n==m || m==0) return 1;

	return f[n]*fi[m]%mod*fi[n-m]%mod;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m;
	cin>>n>>m;
	np[0]=mp[0]=f[0]=1;
	FOR(i,1,1<<20){
		np[i]=np[i-1]*n;np[i]%=mod;
		mp[i]=mp[i-1]*m;mp[i]%=mod;
		f[i]=f[i-1]*i;f[i]%=mod;
	}
	REP(i,1<<20)fi[i]=qp(f[i],mod-2);
	ll res = 0;
	FOR(i,1,n){
		ll t = c(m-i+i-1,i-1);
		t *= c(n-2,i-1); t%= mod;
		t *= f[i-1]; t%= mod;
		t *= mp[n-1-i]; t%= mod;
		if(n-i-2>=0){
			t *= (i+1); t%= mod;
			t *= np[n-i-2]; t%=mod;
		}
		res += t;
		res %= mod;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}