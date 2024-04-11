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

const int mod = 998244353 ;

int r[333333][3];
int n;
vi v[333333];

ll qp(ll c, ll st){
	ll r = 1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

ll solve(int ver,int type,int par=-1){
	if(r[ver][type]!=-1)return r[ver][type];
	ll res = 1;
	int nc=0;
	REP(i,v[ver].size()){
		int nv = v[ver][i];
		if(nv==par)continue;
		nc++;
		//type=0, free
		if(type==0){
			res *= (solve(nv,0,ver)+solve(nv,1,ver)); res %= mod;	
		}
		//type=1, not free
		if(type==1){
			res *= (solve(nv,1,ver)+solve(nv,0,ver)+solve(nv,1,ver)); res %= mod;	
		}
		//type=2, mm to above
		if(type==2){
			res *= (solve(nv,1,ver)+solve(nv,0,ver)+solve(nv,1,ver)); res %= mod;	
		}
	}
	if(type==1){
		ll tmp = res;
		res=0;
		REP(i,v[ver].size()){
			int nv = v[ver][i];
			if(nv==par)continue;
			ll z = tmp * qp((solve(nv,1,ver)+solve(nv,0,ver)+solve(nv,1,ver))%mod,mod-2) % mod * solve(nv,2,ver) %mod;
			res += z; res%=mod;
		}
	}
	//cout<<ver<<' '<<type<<" = " <<res<<endl;
	return r[ver][type]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	CL(r,-1);
	cout<<(solve(0,0)+solve(0,1))%mod<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}