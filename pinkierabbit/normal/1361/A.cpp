#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define MM 1000005
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
int n,m,t[MN],b[MN];
vector<int>G[MN],v[MN];
int buk[MN];
void sol(int u){
	for(int v:G[u])buk[b[v]]=1;
	int x=1;
	while(buk[x])++x;
	b[u]=x;
	for(int v:G[u])buk[b[v]]=0;
}
int main(){int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	F(i,1,n)scanf("%d",&t[i]),v[t[i]].pb(i);
	F(i,2,n)if(v[i-1].empty()&&!v[i].empty())return puts("-1"),0;
	F(i,1,n)for(int x:v[i])sol(x);
//	F(i,1,n)printf("%d,",b[i]);puts("");
	F(i,1,n)if(t[i]!=b[i])return puts("-1"),0;
	F(i,1,n)for(int x:v[i])printf("%d ",x);puts("");
	return 0;
}