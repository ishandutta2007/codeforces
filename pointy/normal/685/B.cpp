// By: Little09
// Problem: CF685B Kay and Snowflake
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF685B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m;
int fa[N],size[N],v[N],ans[N];
vector<int>t[N];
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
void dfs(int x)
{
	size[x]=1;
	for (int i=0;i<t[x].size();i++)
	{
		dfs(t[x][i]);
		size[x]+=size[t[x][i]];
		v[x]=max(v[x],size[t[x][i]]);
	}
	int rt=x,w=v[x];
	for (int i=0;i<t[x].size();i++)
	{
		int y=t[x][i],z=ans[y];
		int tt=max(v[z],size[x]-size[z]);
		while (z!=x)
		{
			int tot=max(v[z],size[x]-size[z]);
			if (tot<w) w=tot,rt=z;
			else if (tot>tt) break;
			tt=tot,z=fa[z];
		}
	}
	ans[x]=rt;
}
int main()
{
	n=read(),m=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();
		fa[i]=x;
		t[x].push_back(i);
	}
	dfs(1);
	while (m--) printf("%d\n",ans[read()]);
	return 0;
}