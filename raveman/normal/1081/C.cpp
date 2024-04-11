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

const int mod = 998244353;

ll f[2222];

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

	f[0]=1;
	FOR(i,1,2222)f[i]=f[i-1]*i,f[i]%=mod;

	int n,m,k;
	cin>>n>>m>>k;


	ll res = m;
	REP(i,k)res*=(m-1),res%=mod;

	res *= f[n-1];res %= mod;
	res *= qp(f[k],mod-2);res%=mod;
	res *= qp(f[n-1-k],mod-2);res%=mod;

	cout<<res<<endl;



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}