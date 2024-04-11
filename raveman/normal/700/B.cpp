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
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k;
vi   v[222222];
bool u[222222];
int c;

int dfs(int ver,int par=-1){
	int sum=0;
	if(u[ver])sum++;
	bool good = 1;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		int t = dfs(v[ver][i],ver);
		sum += t;
		if(t>k)good=0;
	}
	if(2*k-sum>k)good=0;
	if(good) c=ver;
	return sum;
}

ll total;
void dfs2(int ver,int par=-1,int d = 0){
	if(u[ver])total+=d;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		dfs2(v[ver][i],ver,d+1);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,2*k){
		int x;
		scanf("%d",&x);x--;
		u[x]=1;
	}
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(0);
	dfs2(c);
	cout<<total<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}