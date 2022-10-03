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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,q;
int dep[MN],par[MN],ldf[MN],rdf[MN],dfc;
vector<int>G[MN];
void DFS(int u,int pa){
	dep[u]=dep[par[u]=pa]+1;
	ldf[u]=++dfc;
	for(int v:G[u])if(v!=pa)DFS(v,u);
	rdf[u]=dfc;
}
int seq[MN];
int main(){
	int x,y;
	scanf("%d%d",&n,&q);
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	DFS(1,0);
	while(q--){
		int k;
		scanf("%d",&k);
		F(i,1,k)scanf("%d",&seq[i]),seq[i]=seq[i]==1?1:par[seq[i]];
		sort(seq+1,seq+k+1,[](int i,int j){return dep[i]<dep[j];});
		int ok=1;
		F(i,2,k)if(ldf[seq[i]]<ldf[seq[i-1]]||ldf[seq[i]]>rdf[seq[i-1]])ok=0;
		puts(ok?"YES":"NO");
	}
	return 0;
}