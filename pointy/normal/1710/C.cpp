// Author: Little09
// Problem: C. XOR Triangle
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005;
int n,m; 
char s[N];
ll dp[N][2][2][2][2][2][2];

ll dfs(int u,bool a,bool b,bool c,bool x,bool y,bool z)
{
	if (u==n+1)
	{
		if (x&&y&&z) return 1;
		return 0;
	}
	if (dp[u][a][b][c][x][y][z]!=-1) return dp[u][a][b][c][x][y][z];
	ll res=0;
	for (int i=0;i<=1;i++)
	{
		if (a&&i>s[u]-'0') continue;
		for (int j=0;j<=1;j++)
		{
			if (b&&j>s[u]-'0') continue;
			for (int k=0;k<=1;k++)
			{
				if (c&&k>s[u]-'0') continue;
				res=(res+dfs(u+1,a&(s[u]-'0'==i),b&(s[u]-'0'==j),c&(s[u]-'0'==k),x|((i^j)&(j^k)),y|((i^k)&(j^k)),z|((i^k)&(j^i))))%mod;
			}
		}
	}
	dp[u][a][b][c][x][y][z]=res;
	return res;
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
	cin >> (s+1);
	n=strlen(s+1);
	memset(dp,-1,sizeof(dp));
	cout << dfs(1,1,1,1,0,0,0);
	return 0;
}