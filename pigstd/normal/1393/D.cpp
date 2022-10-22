#include<bits/stdc++.h>
using namespace std;

const int M=2010;
int a[M][M],n,m;
long long ans;
int f[M<<1][M<<1],dp[M<<1][M<<1];
char c[M][M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		cin>>c[i]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=c[i][j]-'a'+1;
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=m;j++)cout<<a[i][j]<<' ';
//		puts("");
//	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i+j-1][i-j+m]=a[i][j];
//	for (int i=1;i<n+m;i++)
//	{
//		for (int j=1;j<n+m;j++)cout<<f[i][j]<<' ';
//		puts("");
//	}
	for (int i=1;i<n+m;i++)
		for (int j=1;j<n+m;j++)
			if (f[i][j]==0)dp[i][j]=0;
			else if (i<=2||j<=2)dp[i][j]=1,ans+=1;
			else if (f[i][j]==f[i-2][j]&&f[i][j]==f[i][j-2]&&f[i][j]==f[i-1][j-1]&&f[i][j]==f[i-2][j-2])
				dp[i][j]=min(dp[i-2][j],min(dp[i-2][j-2],dp[i][j-2]))+1,ans+=dp[i][j];
			else dp[i][j]=1,ans+=1;
//	for (int i=1;i<n+m;i++)
//	{
//		for (int j=1;j<n+m;j++)cout<<dp[i][j]<<' ';
//		puts("");
//	}
	cout<<ans;
	return 0;
}

/*
5 5
zbacg
baaac
aaaaa
eaaad
weadd
0 0 0 0 26 0 0 0 0
0 0 0 2 0 2 0 0 0
0 0 1 0 1 0 1 0 0
0 3 0 1 0 1 0 5 0
7 0 1 0 1 0 1 0 23
0 3 0 1 0 1 0 5 0
0 0 1 0 1 0 1 0 0
0 0 0 4 0 4 0 0 0
0 0 0 0 4 0 0 0 0

0 0 0 0 1 0 0 0 0
0 0 0 1 0 1 0 0 0
0 0 1 0 1 0 1 0 0
0 1 0 1 0 1 0 1 0
1 0 1 0 2 0 3 0 1
0 1 0 1 0 2 0 1 0
0 0 1 0 3 0 4 0 0
0 0 0 1 0 1 0 0 0
0 0 0 0 1 0 0 0 0
34
*/