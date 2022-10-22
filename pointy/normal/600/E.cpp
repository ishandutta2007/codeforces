// By: Little09
// Problem: CF600E Lomsat gelral
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF600E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=2e5+5;
int c[N];
vector<int>G[N];
int deth[N],son[N],siz[N],dfn[N],tot,rk[N];
ll ans[N],cnt[N],res,tmp;
void dfs1(int x,int f)
{
	son[x]=-1,deth[x]=deth[f]+1,siz[x]=1,dfn[x]=++tot,rk[tot]=x;
	for (int i:G[x])
	{
		if (i==f) continue;
		dfs1(i,x);
		siz[x]+=siz[i];
		if (son[x]==-1||siz[son[x]]<siz[i]) son[x]=i;
	}
}
void add(int x)
{
	cnt[c[x]]++;
	if (cnt[c[x]]==tmp) res+=c[x];
	else if (cnt[c[x]]>tmp) tmp=cnt[c[x]],res=c[x];
}
void dfs2(int x,int f,bool t)
{
	for (int i:G[x])
	{
		if (i==f||i==son[x]) continue;
		dfs2(i,x,0);
	}
	if (son[x]!=-1) dfs2(son[x],x,1);
	for (int i:G[x])
	{
		if (i==f||i==son[x]) continue;
		for (int j=dfn[i];j<dfn[i]+siz[i];j++)
		{
			add(rk[j]);
		}
	}
	add(x);
	ans[x]=res;
	if (t==0)
	{
		for (int j=dfn[x];j<dfn[x]+siz[x];j++) cnt[c[rk[j]]]=0;
		res=0,tmp=0;
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

int main()
{
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}