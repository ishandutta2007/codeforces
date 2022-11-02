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

int n;
int a[333333];

ll solve(vi v, bool o=0){
	if(v.empty())return 0;
	ll res=0;
	int n0=0;
	for(int i=v.size()-1;i>=0;i--){
		if(v[i]==(o?1:0))n0++;
		else{
			res += n0;
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	int x=0;
	ll r=0;
	vector<vi> g;
	g.pb(vi());
	REP(i,n)g[0].pb(a[i]);
	for(int i=29;i>=0;i--){
		vector<vi> ng;
		ll t0=0,t1=0;
		REP(j,g.size()){
			vi g0,g1,zz;
			REP(z,g[j].size()){
				if(g[j][z]&(1<<i))g1.pb(g[j][z]),zz.pb(1);
				else g0.pb(g[j][z]),zz.pb(0);
			}
			if(!g0.empty())
			ng.pb(g0);
			if(!g1.empty())
			ng.pb(g1);
			t0+=solve(zz);
			t1+=solve(zz,1);
		}
		//cout<<i<<' '<<t0<<' '<<t1<<endl;
		r+=min(t1,t0);
		if(t1>=t0);
		else x+=(1<<i);
		g=ng;
	}
	cout<<r<<' '<<x<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}