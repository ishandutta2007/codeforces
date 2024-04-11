#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=998244353;
const int N=200010;
vector<int>g[N];
int f[N][3],n,pre[N],suc[N],v[N];
void dfs(int p,int fa)
{
	int cnt=g[p].size(),k=0,d=cnt;
	for(int i=0;i<cnt;i++)if(g[p][i]!=fa)dfs(g[p][i],p),k++;else d=k;
	int now=0;pre[now]=1;
	for(int i=0;i<cnt;i++)
	{
		int x=g[p][i];
		if(x==fa)continue;
		now++;
		pre[now]=1ll*pre[now-1]*(f[x][1]+f[x][2])%MOD;
		v[now]=f[x][0];
	}
	now=k+1;suc[now]=1;
	for(int i=cnt-1;i>=0;i--)
	{
		int x=g[p][i];
		if(x==fa)continue;
		now--;
		suc[now]=1ll*suc[now+1]*(f[x][0]+f[x][2])%MOD;
	}
	f[p][0]=pre[k];
	for(int i=d+1;i<=k;i++)f[p][0]=(f[p][0]+1ll*pre[i-1]*v[i]%MOD*suc[i+1])%MOD;
	f[p][1]=1ll*pre[d]*suc[d+1]%MOD;
	for(int i=1;i<=d;i++)f[p][2]=(f[p][2]+1ll*pre[i-1]*v[i]%MOD*suc[i+1])%MOD;
}
int main()
{
	scanf("%d",&n);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
	dfs(1,0);
	printf("%d\n",(f[1][0]+f[1][2])%MOD);
	return 0;
}