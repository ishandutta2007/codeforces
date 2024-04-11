// By: Little09
// Problem: CF342E Xenia and Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF342E
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By: Little09
// Problem: P3379 LCA
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 500 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=200005;
int t[N],nxt[N],h[N],deth[N],cnt;
namespace lca
{
	int tot,w[N];
	struct point
	{
		int deth,id;
		bool operator < (const point & o) const
		{
			return deth<o.deth;
		}
	}a[N];
	point f[N][21];
	void add(int x,int y)
	{
		t[++cnt]=y;
		nxt[cnt]=h[x];
		h[x]=cnt;
	}
	void dfs(int x,int fa)
	{
		deth[x]=deth[fa]+1,w[x]=++tot;
		a[tot].id=x,a[tot].deth=deth[x];
		for (int i=h[x];i;i=nxt[i])
		{
			if (fa==t[i]) continue;
			dfs(t[i],x);
			a[++tot].id=x,a[tot].deth=deth[x];
		}
	}
	void STwork()
	{
		int t=log(tot)/log(2);
		for (int i=1;i<=tot;i++) f[i][0]=a[i];
		for (int j=1;j<=t;j++)
		{
			for (int i=1;i<=tot-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
	point STquery(int l,int r)
	{
		if (l>r) swap(l,r);
		int k=log(r-l+1)/log(2);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}	
	inline int dis(int x,int y)
	{
		int z=STquery(w[x],w[y]).id;
		return deth[x]+deth[y]-2*deth[z];
	}
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

int B;
int w[N],tot,ans[N],b[N];
queue<int>q;
void bfs()
{
	memset(b,-1,sizeof(b));
	for (int i=1;i<=tot;i++) 
	{
		q.push(w[i]);
		b[w[i]]=0;
	}
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int i=h[u];i;i=nxt[i])
		{
			if (b[t[i]]==-1)
			{
				b[t[i]]=b[u]+1;
				q.push(t[i]);
			}
		}
	}
	for (int i=1;i<=n;i++) if (b[i]!=-1) ans[i]=min(ans[i],b[i]);
}

int ask(int x)
{
	int res=ans[x];
	for (int i=1;i<=tot;i++) 
	{
		res=min(res,lca::dis(x,w[i]));
	}
	return res;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) ans[i]=n;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		lca::add(x,y),lca::add(y,x);
	}
	lca::dfs(1,0);
	lca::STwork();
	B=sqrt(m);
	w[++tot]=1;
	for (int i=1;i<=m;i++)
	{
		int tp=read();
		if (tp==1)
		{
			int x=read();
			w[++tot]=x;
		}
		else
		{
			int x=read();
			printf("%d\n",ask(x));
		}
		if (i%B==0)
		{
			bfs();
			tot=0;
		}
	}
	return 0;
}