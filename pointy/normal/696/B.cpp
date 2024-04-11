// By: Little09
// Problem: CF696B Puzzles
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF696B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,fa[N];
vector<int>t[N];
double dp[N],size[N];
void dfs(int x)
{
	size[x]=1;
	for (int i=0;i<t[x].size();i++)
	{
		dfs(t[x][i]);
		size[x]+=size[t[x][i]];
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
	for (int i=2;i<=n;i++) fa[i]=read(),t[fa[i]].push_back(i);
	dfs(1);
	dp[1]=1;
	for (int i=2;i<=n;i++) dp[i]=dp[fa[i]]+1+(size[fa[i]]-size[i]-1)/2.0;
	for (int i=1;i<=n;i++) printf("%.6lf ",dp[i]);
	return 0;
}