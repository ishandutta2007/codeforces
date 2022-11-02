#include<cstdio>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
const int MOD=998244353;
const int N=150010;
int c[N],D[N],son[N],size[N],Top[N],fa[N],L[N],R[N],tot,n,q,revn;
vector<int>g[N];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
void modify(int x,int y){for(;x<=n;x+=x&(-x))(c[x]+=y)%=MOD;}
int get(int x){int s=0;for(;x;x-=x&(-x))(s+=c[x])%=MOD;return s;}
void dfs(int p)
{
	size[p]=1;
	for(auto i:g[p])
	if(i!=fa[p])
	{
		fa[i]=p;
		dfs(i);
		size[p]+=size[i];
		if(size[i]>size[son[p]])son[p]=i;
	}
}
void split(int p,int T)
{
	Top[p]=T;
	L[p]=++tot;
	if(son[p])split(son[p],T);
	for(auto i:g[p])if(i!=fa[p]&&i!=son[p])split(i,i);
	R[p]=tot;
}
int main()
{
	scanf("%d%d",&n,&q);revn=mypow(n,MOD-2);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
	dfs(1);
	split(1,1);
	rep(i,q)
	{
		int opt,v,d;
		scanf("%d%d",&opt,&v);
		if(opt==1)
		{
			scanf("%d",&d);
			modify(1,1ll*d*size[v]%MOD*revn%MOD);modify(L[v],MOD-1ll*d*size[v]%MOD*revn%MOD);
			modify(R[v]+1,1ll*d*size[v]%MOD*revn%MOD);
			if(son[v])modify(L[son[v]],1ll*d*(n-size[son[v]])%MOD*revn%MOD),modify(R[son[v]]+1,MOD-1ll*d*(n-size[son[v]])%MOD*revn%MOD);
			(D[v]+=d)%=MOD;
		}
		else
		{
			int ans=get(L[v]);
			for(int x=Top[v];x!=1;x=Top[fa[x]])ans=(ans+1ll*D[fa[x]]*(n-size[x])%MOD*revn)%MOD;
			(ans+=D[v])%=MOD;
			printf("%d\n",ans);
		}
	}
	return 0;
}