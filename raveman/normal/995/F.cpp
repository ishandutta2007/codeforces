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

const int mod = 1000000007;

int n,D;
int p[3333];
int d[3333][3333];
int sd[3333][3333];
int r[3333];
vi v[3333];

int C[3333][3333];

int solve(int ver, int color);

int sumSolve(int ver,int color){
	if(color<=0)return 0;
	if(sd[ver][color]!=-1) return sd[ver][color];
	int res = solve(ver,color)+sumSolve(ver,color-1);
	if(res>=mod)res-=mod;
	return sd[ver][color]=res;
}

int solve(int ver, int color){
	if(d[ver][color]!=-1) return d[ver][color];
	ll res = 1;
	REP(i,v[ver].size()){
		res *= sumSolve(v[ver][i],color);
		res %= mod;
	}
	return d[ver][color]=res;
}

ll f[3333];
ll invf[3333];

int c(int n,int m){
	if(m>n) return 0;

	ll res = 1;
	FOR(i,n-m+1,n+1){
		res *= i;
		res %= mod;
	}
	res *= invf[m];
	res %= mod;
	return res;
}

ll qp(ll c,ll st){
	ll r =1;
	while(st){
		if(st&1)r*=c,r%=mod;
		st>>=1;
		c*=c,c%=mod;
	}
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,3333)f[i]=f[i-1]*i%mod;
	REP(i,3333)invf[i]=qp(f[i],mod-2);

	REP(i,3333){
		C[i][i]=C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	CL(sd,-1);
	CL(d,-1);


	cin>>n>>D;
	REP(i,n-1)scanf("%d",p+i+1),p[i+1]--,v[p[i+1]].pb(i+1);


	FOR(i,1,n+1){
		r[i] = sumSolve(0,i);
		FOR(j,1,i){
			r[i] = (r[i] - r[j] * ll(C[i][j]))%mod;
			if(r[i]<0)r[i]+=mod;
		}
	}


	ll res = 0;
	FOR(i,1,n+1){
//		cout<<i<<": "<<r[i]<<endl;
		res = (res + r[i] * ll(c(D,i))) % mod;
	}
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}