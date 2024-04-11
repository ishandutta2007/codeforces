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
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,q;
int p[333333];
vi  v[333333];

int sz[333333];
int  c[333333];

void dfs(int ver){
	sz[ver] = 1;
	int biggest = -1;
	REP(i,v[ver].size()){
		dfs(v[ver][i]);
		sz[ver] += sz[v[ver][i]];
		if(biggest == -1 || sz[biggest] < sz[v[ver][i]]) biggest = v[ver][i];
	}
	if(biggest==-1) c[ver]=ver;
	else{
		c[ver] = c[biggest];
		while((sz[ver] - sz[c[ver]])*2 > sz[ver]) c[ver] = p[c[ver]];
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n-1)scanf("%d",p+i+1),p[i+1]--,v[p[i+1]].pb(i+1);

	dfs(0);

	REP(i,q){
		int x;
		scanf("%d",&x);
		x--;
		printf("%d\n",c[x]+1);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}