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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m,k;
const int mod = 1000000007;

ll qp(ll c, ll st){
	if(st==-1)return qp(c,mod-2);
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		st>>=1;
		c*=c;c%=mod;
	}

	return r;
}


ll f[1111111];
ll invf[1111111];

ll C(int n,int m){
	if(m<0)return 0;
	if(m>n)return 0;
	return ((((f[n]*invf[m])%mod)*invf[n-m])%mod);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	f[0]=1;
	FOR(i,1,1111111)f[i]=(f[i-1]*i)%mod;
	REP(i,1111111)invf[i]=qp(f[i],mod-2);
	ll i2 = qp(2,mod-2);

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m>>k;
		m--;
		ll res =C(n,m); 
		ll r = i2;
		FOR(i,1,n+1){
			res=(res+(((((i+3)*r)%mod)*C(n-i,m-i))%mod))%mod;
			r*=2;r%=mod;
		}
		res=(res*k)%mod;
		res=(res*qp(i2,n-1))%mod;
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}