// By: Little09
// Problem: CF1077F2 Pictures with Kittens (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1077F2
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000;
const int N=5005;
int n,m,k;
ll a[N],dp[N][N];
int q[N][N],l[N],r[N];
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
inline void insert(int id,int x)
{
	ll y=dp[id][x];
	while (l[id]<=r[id]&&dp[id][q[id][r[id]]]<=y) r[id]--;
	r[id]++;
	q[id][r[id]]=x;
}
inline void update(int id,int x)
{
	while (l[id]<=r[id]&&q[id][l[id]]<x) l[id]++;
}
int main()
{
	n=read(),k=read(),m=read();
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			dp[i][j]=-inf;
		}
	}
	for (int i=1;i<=n;i++) a[i]=read();
	dp[0][0]=0;
	for (int i=0;i<=m;i++) l[i]=1,r[i]=0;
	for (int i=0;i<=m;i++) insert(i,0);
	for (int i=1;i<=n;i++)
	{
		int u=min(i,m),p=max(0,i-k);
		for (int j=0;j<=m;j++) update(j,p);
		for (int j=1;j<=u;j++) 
		{
			dp[j][i]=dp[j-1][q[j-1][l[j-1]]]+a[i];
		}
		for (int j=0;j<=m;j++) insert(j,i);
	}
	ll ans=-1;
	for (int i=n-k+1;i<=n;i++) ans=max(ans,dp[m][i]);
	cout << ans;
	return 0;
}