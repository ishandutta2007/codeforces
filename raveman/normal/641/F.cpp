//#pragma comment(linker, "/STACK:60777216")  

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m1,m2;
pii e1[1111111],e2[1111111];

int convert(int x){
	if(x>0) return x-1;
	if(x<0) return -x-1+n;
}
struct Graph{
	Graph(){
		CL(g,0);
	}
	void addEdge(int x,int y){
		x=convert(x);
		y=convert(y);
		g[(x+n)%(2*n)][y]=1;
		g[(y+n)%(2*n)][x]=1;
		bs[(x+n)%(2*n)][y]=true;
		bs[(y+n)%(2*n)][x]=true;
	}
	bool g[2222][2222];
	bool used[2222];

	void dfs1(int ver){
		used[ver]=true;
		REP(i,2*n)if(!used[i] && g[ver][i]) dfs1(i);
		order.pb(ver);
	}
	void dfs2(int ver){
		used[ver]=true;
		component.pb(ver);
		REP(i,2*n)if(!used[i] && g[i][ver])dfs2(i);
	}
	bool issolvable(){
		CL(used,0);
		REP(i,2*n)if(!used[i])dfs1(i);
		CL(used,0);
		REP(i,2*n){
			int v = order[2*n-1-i];
			if(!used[v]){
				dfs2(v);
				allc.pb(component);
				component.clear();
			}
		}
		CL(cid,0);
		REP(i,allc.size())REP(j,allc[i].size())cid[allc[i][j]]=i;
		REP(i,n)if(cid[i] == cid[i+n]) return false;
		return true;
	}
	bitset<2000> bs[2000];
	void printsolution(){
		REP(i,n){
			if(i)printf(" ");
			printf("%d", (cid[i]>cid[i+n])?1:0);
		}
		puts("");
	}
	void psol(int ver){
		REP(i,n){
			if(i)printf(" ");
			if(bs[ver][i]) printf("1");
			else if(bs[ver][i+n]) printf("0");
			else printf("%d", (cid[i]>cid[i+n])?1:0);
		}
		puts("");
	}
	void psol(int ver,int ver2){
		REP(i,n){
			if(i)printf(" ");
			if(bs[ver][i]) printf("1");
			else if(bs[ver][i+n]) printf("0");
			else if(bs[ver2][i]) printf("1");
			else if(bs[ver2][i+n]) printf("0");
			else printf("%d", (cid[i]>cid[i+n])?1:0);
		}
		puts("");
	}
	int cid[2222];
	vector<vi> allc;
	vi order,component;
	void dfs3(int ver){
		used[ver]=true;
		bs[ver][ver]=true;
		REP(i,2*n)if(g[ver][i]){
			if(!used[i])dfs3(i);
			bs[ver]|=bs[i];
		}
	}
	void findc(){
		CL(used,0);
		REP(i,2*n)if(!used[i])dfs3(i);
	}
	
};

bool isbad(bitset<2000> bs){
	REP(i,n)if(bs[i] && bs[i+n])return true;
	return false;
}

Graph g1,g2;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m1>>m2;
	REP(i,m1)scanf("%d %d",&e1[i].first,&e1[i].second);
	REP(i,m2)scanf("%d %d",&e2[i].first,&e2[i].second);

	REP(i,m1)g1.addEdge(e1[i].first,e1[i].second);
	REP(i,m2)g2.addEdge(e2[i].first,e2[i].second);

	bool is1 = g1.issolvable();
	bool is2 = g2.issolvable();

	if(is1 && is2){
		g1.findc();
		g2.findc();
		REP(i,2*n)if(g1.bs[i]!=g2.bs[i]){
			if (isbad(g1.bs[i]) && isbad(g2.bs[i]))continue;
			if(isbad(g1.bs[i])) {
				g2.psol(i);
				return 0;
			}else if(isbad(g2.bs[i])){
				g1.psol(i);
				return 0;
			}else{
				REP(j,2*n)if(g1.bs[i][j] != g2.bs[i][j]){
					if(g1.bs[i][j]){
						if(isbad(g2.bs[(j+n)%(2*n)])) continue;
						g2.psol(i,(j+n)%(2*n));
						return 0;
					}
					else if(g2.bs[i][j]){
						if(isbad(g1.bs[(j+n)%(2*n)])) continue;
						g1.psol(i,(j+n)%(2*n));
						return 0;
					}
				}
			}
		}
		puts("SIMILAR");
	}else if(is1){
		g1.printsolution();
	}else if(is2){
		g2.printsolution();
	}else{
		puts("SIMILAR");
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}