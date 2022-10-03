// Author : PinkRabbit
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5005
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
int n,m,a,b,c,t,vis[MN],col[MN],ok;
vector<int>G[MN];
int num[MN*2];
void dfs(int u,int co){
	vis[u]=1,col[u]=co,++num[co];
	for(int v:G[u])if(!vis[v])dfs(v,co^1);else if(col[v]==col[u])ok=0;
}
int f[MN][MN],g[MN][MN];
int cho[MN*2];
int main(){int x,y;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c),ok=1;
	F(i,1,m)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	F(i,1,n)if(!vis[i])dfs(i,t<<1),++t;
	if(!ok)return puts("NO"),0;
	f[0][0]=1;
	F(i,0,t-1){
		F(j,0,n)if(f[i][j]){
			f[i+1][j+num[i<<1]]=1,g[i+1][j+num[i<<1]]=i<<1;
			f[i+1][j+num[i<<1|1]]=1|1,g[i+1][j+num[i<<1|1]]=i<<1|1;
		}
	}
	if(!f[t][b])return puts("NO"),0;
	puts("YES");
	int now=b;
	dF(i,t,1){
		int ch=g[i][now];
		cho[ch]=1;
		now-=num[ch];
	}
	F(i,1,n)printf("%d",cho[col[i]]?2:a?--a,1:3);
	puts("");
	return 0;
}