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
int n;
int d[MN],mxd;
vector<int>G[MN];
vector<pii>Ans;
void DFS(int u,int p,int t){
	int ot=t;
	Ans.pb({u,t});
	for(int v:G[u])if(v!=p){
		if(t==mxd)t=mxd-d[u],Ans.pb({u,t});
		++t;
		DFS(v,u,t);
		Ans.pb({u,t});
	}
	if(p&&t!=ot-1)t=ot-1,Ans.pb({u,t});
}
int main(){int x,y;
	scanf("%d",&n);
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x),++d[x],++d[y];
	mxd=*max_element(d+1,d+n+1);
	DFS(1,0,0);
	printf("%d\n",(int)Ans.size());
	for(pii p:Ans)printf("%d %d\n",p.fi,p.se);
	return 0;
}