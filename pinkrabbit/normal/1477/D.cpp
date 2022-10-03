#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
int p1[MN],p2[MN];
void output(){
	static int t[MN];
	F(i,1,n)t[p1[i]]=i;
	F(i,1,n)p1[i]=t[i];
	F(i,1,n)t[p2[i]]=i;
	F(i,1,n)p2[i]=t[i];
	F(i,1,n)printf("%d%c",p1[i]," \n"[i==n]);
	F(i,1,n)printf("%d%c",p2[i]," \n"[i==n]);
}
vector<int>G[MN];
int vis[MN],cnt;
void DFS0(int u){
	++cnt,vis[u]=1;
	for(int v:G[u])if(!vis[v])DFS0(v);
}
vector<int>T[MN];
set<int>G2[MN];
set<int>unvis;
int par[MN];
void DFS1(int u){
	vis[u]=1,unvis.erase(u);
	int p=0;
	auto it=unvis.end();
	while((it=unvis.upper_bound(p))!=unvis.end()){
		p=*it;
		if(G2[u].find(p)==G2[u].end()){
//			printf("%d -> %d\n",u,p);
			T[u].pb(p);
			par[p]=u;
			DFS1(p);
		}
	}
}
void add(int u,int typ){
	// typ == 0 : do not add parent
	// typ == 1 : add parent
//	printf("add(%d,%d)\n",u,typ);
	// p1
	int oldcnt=cnt;
	p1[++cnt]=u;
	for(int v:T[u])if(T[v].empty())p1[++cnt]=v;
	if(typ)p1[++cnt]=par[u];
	// p2
	cnt=oldcnt;
	for(int v:T[u])if(T[v].empty())p2[++cnt]=v;
	if(typ)p2[++cnt]=par[u];
	p2[++cnt]=u;
}
void DFS2(int u){
	int cc=0;
	for(int v:T[u])if(T[v].empty())++cc;
//	printf("DFS2(%d) (cc=%d)\n",u,cc);
	if(cc){
		add(u,0);
		for(int v:T[u])if(!T[v].empty())DFS2(v);
	}else{
		int w=T[u][0];
		add(w,1);
		for(int v:T[u])if(v!=w)DFS2(v);
		for(int v:T[w])if(!T[v].empty())DFS2(v);
	}
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,n)G[i].clear(),vis[i]=0;
	F(i,1,m)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	cnt=0,DFS0(1);
	if(cnt<n){
		int j=0;
		F(i,1,n)if(vis[i])p1[++j]=i;
		F(i,1,n)if(!vis[i])p1[++j]=i;
		j=0;
		F(i,1,n)if(!vis[i])p2[++j]=i;
		F(i,1,n)if(vis[i])p2[++j]=i;
	}else{
		cnt=0;
		F(i,1,n)if((int)G[i].size() == n-1)
			++cnt,p1[cnt]=i,p2[cnt]=i;
		F(i,1,n){
			G2[i].clear();
			for(int v:G[i])G2[i].insert(v);
		}
		unvis.clear();
		F(i,1,n)vis[i]=0,T[i].clear(),unvis.insert(i);
		F(i,1,n)if((int)G[i].size() != n-1){
			if(vis[i])continue;
			par[i]=0,DFS1(i);
			DFS2(i);
		}
	}
	output();
}	return 0;
}
/*
6

4 2
1 2
3 4

6 4
1 2
1 3
3 5
3 6

2 1
1 2

5 6
1 3
1 5
2 4
2 5
3 4
3 5

5 6
1 3
1 5
2 4
2 5
3 4
3 5

5 5
1 2
2 3
3 4
1 4
4 5

*/