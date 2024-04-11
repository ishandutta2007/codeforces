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

int n,a,b,da,db;
vi v[111111];

int dfs(int ver,int to,int dist=0,int par=-1){
	if(ver==to)return dist;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		int t = dfs(v[ver][i],to,dist+1,ver);
		if(t!=-1)return t;
	}
	return -1;
}

int md;
int mdver;

void dfs2(int ver,int dist=0,int par=-1){
	if(dist>md){
		md=dist;
		mdver=ver;
	}
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		dfs2(v[ver][i],dist+1,ver);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>a>>b>>da>>db;
		REP(i,n)v[i].clear();
		REP(i,n-1){
			int x,y;
			scanf("%d %d",&x,&y);
			x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		a--,b--;

		if(db<=2*da || dfs(a,b)<=da){puts("Alice");continue;}
		md=-1;
		dfs2(0);
		md=-1;
		dfs2(mdver);
		if(md<=2*da)puts("Alice");
		else puts("Bob");
		//puts("DONT");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}