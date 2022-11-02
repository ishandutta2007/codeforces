#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=1e9+7;
const int N=100010;
int siz[N],p[N],n,m;
vector<pair<int,int>>g[N];
long long cnt[N];
void dfs(int p,int fa)
{
	siz[p]=1;
	for(auto i:g[p])
	if(i.first!=fa)
	{
		dfs(i.first,p);
		siz[p]+=siz[i.first];
		cnt[i.second]=1ll*siz[i.first]*(n-siz[i.first]);
	}
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
    	scanf("%d",&n);
    	rep(i,n)g[i].clear();
    	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(mp(y,i));g[y].pb(mp(x,i));}
    	scanf("%d",&m);
    	rep(i,m)scanf("%d",&p[i]);
    	for(;m<n-1;p[++m]=1);
    	dfs(1,0);
    	sort(p+1,p+m+1);
    	sort(cnt+1,cnt+n);
    	int ans=cnt[n-1]%MOD;
    	for(int i=n-1;i<=m;i++)ans=1ll*ans*p[i]%MOD;
    	rep(i,n-2)ans=(ans+1ll*cnt[i]*p[i])%MOD;
    	printf("%d\n",ans);
    }
    return 0;
}