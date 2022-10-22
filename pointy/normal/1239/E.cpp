// By: Little09
// Problem: CF1239E Turtle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1239E
// Memory Limit: 500 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=26,M=50005;
int n; 
int a[N*2],s,p[N];
bitset<M*N*2>dp[2*N][N];
bool used[2*N];
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
	for (int i=1;i<=2*n;i++) a[i]=read()+1;
	sort(a+1,a+n*2+1);
	dp[2][0][0]=1;
	for (int i=3;i<=2*n;i++)
	{
		int u=min(i-2,n-1);
		s+=a[i];
		for (int j=u;j>=1;j--)
		{
			dp[i][j]=dp[i-1][j]|(dp[i-1][j-1]<<a[i]);
		}
		dp[i][0]=dp[i-1][0];
	}
	int ans=1e9;
	for (int i=0;i<=s;i++)
	{
		if (dp[2*n][n-1][i]) ans=min(ans,max(i,s-i));
	}
	int tot=2*n,u=n-1,flag=0;
	while (ans)
	{
		if (dp[tot-1][u][ans]) tot--,flag++;
		else used[tot]=1,ans-=a[tot],tot--,u--;
	}
	int cnt=0;
	for (int i=3;i<=2*n;i++) 
	{
		if (used[i]==0) p[++cnt]=a[i];
	}
	sort(p+1,p+cnt+1);
	printf("%d ",a[1]-1);
	for (int i=1;i<=cnt;i++) printf("%d ",p[i]-1);
	cnt=0;
	puts("");
	for (int i=3;i<=2*n;i++) 
	{
		if (used[i]==1) p[++cnt]=a[i];
	}
	sort(p+1,p+cnt+1);
	for (int i=cnt;i>=1;i--) printf("%d ",p[i]-1);
	printf("%d ",a[2]-1);
	return 0;
}