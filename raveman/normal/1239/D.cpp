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

vi v[1111111];
vi vr[1<<20];
int n,m;

vi comp;
bool u[1<<20];
vi o;

void dfs1(int ver){
	if(u[ver])return;
	u[ver]=1;
	REP(i,v[ver].size())dfs1(v[ver][i]);
	o.pb(ver);
}

void dfs2(int ver){
	if(u[ver])return;
	u[ver]=1;
	comp.pb(ver);
	REP(i,vr[ver].size())dfs2(vr[ver][i]);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		int x,y;
		REP(i,n)v[i].clear(),vr[i].clear();
		REP(i,m){
			scanf("%d %d",&x,&y);
			x--,y--;
			if(x!=y)v[x].pb(y),vr[y].pb(x);
		}
		REP(i,n)u[i]=0;
		o.clear();
		REP(i,n)if(!u[i])dfs1(i);
		REP(i,n)u[i]=0;
		reverse(o.begin(),o.end());
		vector<vi> c;
		REP(i,n)if(!u[o[i]]){
			comp.clear();
			dfs2(o[i]);
			c.pb(comp);
			//REP(j,comp.size())cout<<comp[j]<<' ';puts("");
		}

		if(c.size()==1) puts("No");
		else{
			puts("Yes");
			REP(i,n)u[i]=0;
			cout<<c.back().size()<<" "<<n-c.back().size()<<endl;
			REP(i,c.back().size()){
				printf("%d ",c.back()[i]+1);
				u[c.back()[i]]=1;
			}
			puts("");
			REP(i,n)if(!u[i])printf("%d ",i+1);
			puts("");
		}
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}