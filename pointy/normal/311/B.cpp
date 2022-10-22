// Author: Little09
// Problem: CF311B Cats Transport
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF311B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
const int N=1e5+5,M=105;
int n,m,p;
ll d[N],f[N],s[N];
ll dp[N],tmp[N];
ll X(int x){return x;}
ll Y(int x){return tmp[x]+s[x];}
double slope(int x,int y)
{
	if (X(y)==X(x)) return inf;
	return (Y(y)-Y(x))/(X(y)-X(x));
}
int q[N],l,r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> p;
	for (int i=2;i<=n;i++) cin >> d[i];
	for (int i=1;i<=n;i++) d[i]+=d[i-1];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		f[i]=y-d[x];
	}
	sort(f+1,f+m+1);
	for (int i=1;i<=m;i++) s[i]=s[i-1]+f[i];
	for (int i=1;i<=m;i++) dp[i]=inf;
	dp[0]=0;
	if (p>m)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int j=1;j<=p;j++)
	{
		for (int i=0;i<=m;i++) tmp[i]=dp[i];
		l=1,r=1,q[l]=0;
		for (int i=1;i<=m;i++)
		{
			while (l<r&&slope(q[l],q[l+1])<=f[i]) l++;
			dp[i]=tmp[q[l]]+f[i]*(i-q[l])-s[i]+s[q[l]];
			while (l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) r--;
			q[++r]=i;
		}
	}
	cout << dp[m] << endl;
	return 0;
}