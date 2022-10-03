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
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
vector<int>G[MN];
int dep[MN],siz[MN],f[MN];
void DFS(int u,int p){
	dep[u]=dep[p]+1,siz[u]=1;
	for(int v:G[u])if(v!=p)DFS(v,u),siz[u]+=siz[v];
}
int main(){
	int x,y;
	scanf("%d%d",&n,&k);
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	DFS(1,0);
	F(i,1,n)f[i]=dep[i]-siz[i];
	sort(f+1,f+n+1);
	reverse(f+1,f+n+1);
	ll sum=0;
	F(i,1,k)sum+=f[i];
	printf("%lld\n",sum);
	return 0;
}