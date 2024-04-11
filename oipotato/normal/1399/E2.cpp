#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=100010;
struct data{int to,w,c;};
vector<data>g[N];
long long a[2][N*21],S,sum;
int cnt[2],n,siz[N];
void dfs(int p,int fa,long long dep)
{
	siz[p]=0;
	for(auto i:g[p])
	if(i.to!=fa)
	{
		dfs(i.to,p,dep+i.w);
		siz[p]+=siz[i.to];
		for(int x=i.w;x;x>>=1)a[i.c][++cnt[i.c]]=1ll*((x>>1)+(x&1))*siz[i.to];
	}
	if(!siz[p])siz[p]=1,sum+=dep;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%lld",&n,&S);
		rep(i,n)g[i].clear();
		cnt[0]=cnt[1]=0;sum=0;
		rep(i,n-1)
		{
			int u,v,w,c;
			scanf("%d%d%d%d",&u,&v,&w,&c);c--;
			g[u].pb({v,w,c});
			g[v].pb({u,w,c});
		}
		dfs(1,0,0);
		sort(a[0]+1,a[0]+cnt[0]+1);
		sort(a[1]+1,a[1]+cnt[1]+1,greater<long long>());
		// rep(j,2)rep(i,cnt[j-1])printf("%lld%c",a[j-1][i]," \n"[i==cnt[j-1]]);
		rep(i,cnt[0])sum-=a[0][i];
		int now=1;
		for(;now<=cnt[1]&&sum>S;sum-=a[1][now++]);
		int ans=2*(now-1)+cnt[0];
		rep(i,cnt[0])
		{
			sum+=a[0][i];
			for(;now<=cnt[1]&&sum>S;sum-=a[1][now++]);
			if(sum>S)break;
			ans=min(ans,2*(now-1)+cnt[0]-i);
		}
		printf("%d\n",ans);
	}
	return 0;
}