// Author: Little09
// Problem: CF1446C Xor Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1446C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5,M=32;
int ch[N*M][2],tot=1,dp[N*M];
void insert(int x)
{
	int p=1;
	for (int i=30;i>=0;i--)
	{
		bool u=(1<<i)&x;
		if (ch[p][u]==0) ch[p][u]=++tot;
		p=ch[p][u];
	}
	dp[p]=1;
}
int dfs(int x)
{
	if (!x) return 0;
	if (dp[x]) return dp[x];
	int u=dfs(ch[x][0]),v=dfs(ch[x][1]);
	if (!u||!v) return u+v;
	return max(u,v)+1;
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
	for (int i=1;i<=n;i++) insert(read());
	cout << n-dfs(1);
	return 0;
}