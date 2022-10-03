#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,q,k;
vector<int>G[MN];
int siz[MN],par[MN],ldf[MN],rdf[MN],dfc;
void DFS(int u,int p){
	par[u]=p,siz[u]=1,ldf[u]=++dfc;
	for(int v:G[u])if(v!=p)DFS(v,u),siz[u]+=siz[v];
	rdf[u]=dfc;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x,y;
	scanf("%d",&n);
	F(i,1,n)G[i].clear();
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	if(n&1){printf("%d %d\n%d %d\n",x,y,x,y);continue;}
	dfc=0,DFS(1,0);
	int ok=1;
	F(i,1,n)if(siz[i]==n/2)x=i,y=par[i],ok=0;
	if(ok){printf("%d %d\n%d %d\n",x,y,x,y);continue;}
	int z=0;
	F(i,1,n)if(siz[i]==1&&ldf[x]<=ldf[i]&&ldf[i]<=rdf[x])z=i;
	printf("%d %d\n",z,par[z]);
	printf("%d %d\n",z,y);
}	return 0;
}