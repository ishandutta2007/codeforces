// By: Little09
// Problem: CF526F Pudding Monsters
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF526F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=400;
int n,a[N];
int dp[N][M+5];

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
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=M;j++)
		{
			int x=i+j+a[i];
			if (x>n) dp[i][j]=1;
			else dp[i][j]=dp[x][j]+1;
		}
	}
	int q=read();
	while (q--)
	{
		int p=read(),k=read();
		if (k<=M)
		{
			printf("%d\n",dp[p][k]);
			continue;
		}
		int cnt=0;
		while (p<=n) p=p+a[p]+k,cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}