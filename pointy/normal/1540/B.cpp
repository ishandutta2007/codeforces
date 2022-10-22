// By: Little09
// Problem: CF1540B Tree Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1540B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
const ll mod=1e9+7;
const int N=405;
int n;
int t[N],nxt[N],cnt,h[N];
int deth[N],fa[N][12];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int u,int f)
{
	deth[u]=deth[f]+1;
	fa[u][0]=f;
	for (int i=1;i<=10;i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	} 
	for (int i=h[u];i;i=nxt[i])
	{
		if (t[i]!=f) dfs(t[i],u);
	}
}
int LCA(int x,int y)
{
	if (deth[x]<deth[y]) swap(x,y);
	for (int i=10;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
    if (x==y) return x;
    for (int i=10;i>=0;i--)
    {
    	if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
ll ans,f[N][N];
int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++) f[i][0]=0;
	for (int i=1;i<=n;i++) f[0][i]=1;
	ll inv2=ksm(2,mod-2);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[i][j]=(f[i-1][j]+f[i][j-1])*inv2%mod;
		}
	}
	ll tmp=ksm(n,mod-2);
	for (int x=1;x<=n;x++)
	{
		mem(deth),mem(fa);
		dfs(x,0);
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				int k=LCA(i,j);
				int x=deth[j]-deth[k],y=deth[i]-deth[k];
				ans=(ans+f[x][y]*tmp%mod)%mod;
			}
		}
	}
	cout << ans;
	return 0;
}