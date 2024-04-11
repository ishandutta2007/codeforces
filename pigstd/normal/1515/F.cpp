#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,m,x,a[M],f[M],ans[M],cnt,cnt2;
struct edge{int u,v;}e[M];
vector<pair<int,int> >v[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void dfs(int u,int fa,int id)
{
	for (int i=0;i<v[u].size();i++)
	{
		int to=v[u][i].x,p=v[u][i].y;
		if (to==fa)continue;
		dfs(to,u,p);
	}
	if (u==1)return;
	if (a[u]>=x)a[fa]+=a[u]-x,ans[++cnt]=id;
	else ans[--cnt2]=id;
}

signed main()
{
	cnt2=n=read(),m=read(),x=read();int sum=0;
	for (int i=1;i<=n;i++)a[i]=read(),f[i]=i,sum+=a[i];
	for (int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read();
		if (find(e[i].u)==find(e[i].v))continue;
		f[find(e[i].u)]=find(e[i].v);
		v[e[i].u].pb(mp(e[i].v,i)),v[e[i].v].pb(mp(e[i].u,i));
	}
	for (int i=1;i<=n;i++)
		if (find(i)!=find(1))return puts("NO"),0;
	if (sum<(n-1)*x)return puts("NO"),0;
	puts("YES");dfs(1,0,0);
	for (int i=1;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}