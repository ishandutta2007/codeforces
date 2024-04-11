#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
#define ll long long
ll n,size[N],sum[N],s;
int h[N],nxt[N],t[N],cnt;
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs1(int u,int fa,ll dis)
{
	size[u]=1;
	sum[1]+=dis;
	if (dis%2==0) s++;
	for (int i=h[u];i;i=nxt[i]) 
	{
		if (t[i]!=fa) 
		{
			dfs1(t[i],u,dis+1);
			size[u]+=size[t[i]];
		}
	}
}
void dfs2(int u,int fa)
{
	if (fa!=0) sum[u]=sum[fa]-size[u]+(n-size[u]);
	for (int i=h[u];i;i=nxt[i]) 
	{
		if (t[i]!=fa) 
		{
			dfs2(t[i],u);
		}
	}
}
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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
int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);	
	}
	dfs1(1,0,0);
	dfs2(1,0);
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=sum[i];
	ans/=2;
	ans+=s*(n-s);
	cout << ans/2 << endl;
	return 0;
}