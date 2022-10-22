// Author: Little09
// Problem: CF1575H Holiday Wall Ornaments
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1575H
// Memory Limit: 500 MB
// Time Limit: 3000 ms
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
int a[N],b[N],kmp[N],tran[N][2],dp[N][N][N];

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
inline char readchar()
{
	char C=getchar();
    while (C<'0'||C>'1') C=getchar();
    return C;
}
inline int raed(){return read();}

void prefix_function()
{
	kmp[0]=-1;
	if (b[1]==0) tran[0][0]=1;
	else tran[0][1]=1;
	for (int i=1;i<=m;i++)
	{
		int j=kmp[i-1];
		while (j!=-1&&b[j+1]!=b[i]) j=kmp[j];
		kmp[i]=j+1;
		if (b[i+1]==0) tran[i][0]=i+1;
		else tran[i][0]=tran[kmp[i]][0];
		if (b[i+1]==1) tran[i][1]=i+1;
		else tran[i][1]=tran[kmp[i]][1];
	}
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=readchar()-'0';
	for (int i=1;i<=m;i++) b[i]=readchar()-'0';
	b[m+1]=2;
	prefix_function();
	memset(dp,20,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			for (int k=0;k<=n-m;k++)
			{
				for (int t=0;t<=1;t++)
				{
					int u=tran[j][t],v=k+(u==m);
					dp[i][u][v]=min(dp[i][u][v],dp[i-1][j][k]+(a[i]!=t));
				}
			}
		}
	}
	for (int i=0;i<=n-m+1;i++)
	{
		int ans=n+1;
		for (int j=0;j<=m;j++) ans=min(ans,dp[n][j][i]);
		if (ans==n+1) ans=-1;
		printf("%d ",ans);
	}
	return 0;
}