// By: Little09
// Problem: CF1579G Minimal Coverage
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1579G
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=10005;
int n,m,T; 
const int inf=1e9;
int a[N],dp[2][N];

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

void work()
{
	n=read(),m=0;
	for (int i=1;i<=n;i++) a[i]=read(),m=max(m,a[i]);
	m*=2;
	for (int i=0;i<=m;i++) dp[1][i]=inf;
	dp[1][a[1]]=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=m;j++) dp[i%2][j]=inf;
		for (int j=0;j<=m;j++)
		{
			int x=j,y=dp[(i-1)%2][j];
			y+=a[i],x=max(x-a[i],0);
			if (x<=m&&y<=m) dp[i%2][x]=min(dp[i%2][x],y);
			x=j,y=dp[(i-1)%2][j];
			x+=a[i],y=max(y-a[i],0);
			if (x<=m&&y<=m) dp[i%2][x]=min(dp[i%2][x],y);
		}
	}
	int ans=inf;
	for (int i=0;i<=m;i++)
	{
		ans=min(ans,i+dp[n%2][i]);
	}
	printf("%d\n",ans);
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}