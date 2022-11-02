#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
#define lmr gay
long long ans;
int a[300010],pos[300010],n,m,now,num;
vector<int> g[300010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	now=1;
	for(int i=1;i<=n;i++)
	{
		for(;now+1<=n&&!num;)
		{
			now++;
			for(auto j:g[a[now]])if(pos[j]>=i&&pos[j]<=now)num++;
		}
		ans+=now-i+(!num);
		for(auto j:g[a[i]])if(pos[j]>=i&&pos[j]<=now)num--;
	}
	printf("%lld\n",ans);
	return 0;
}