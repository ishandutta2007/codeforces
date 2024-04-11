#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> a[100005];
int n,m,q,f[100005],g[100005];
ll ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u<v) swap(u,v);
		f[u]++;
		g[v]++;
		a[v].push_back(u);
	}
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
		ans+=1ll*f[i]*g[i];
	printf("%I64d\n",ans);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		ans-=1ll*f[x]*g[x];
		f[x]+=g[x],g[x]=0;
		for(int j=0;j<a[x].size();j++)
		{
			int u=a[x][j];
			ans-=1ll*f[u]*g[u];
			f[u]--,g[u]++;
			ans+=1ll*f[u]*g[u];
			a[u].push_back(x);
		}
		while(!a[x].empty()) a[x].pop_back(); 
		printf("%I64d\n",ans);
	}
	return 0;
}