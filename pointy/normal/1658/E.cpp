// Author: Little09
// Problem: CF1658E Gojou and Matrix Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1658E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N=2007,M=4000005,inf=1e9;
int n,k; 
int a[M],b[M],c[N][N],ans[M];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n>> k;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int x;
			cin >> x;
			c[i][j]=x;
			a[x]=i,b[x]=j;
		}
	}
	int lx=inf,rx=-inf,ly=inf,ry=-inf;
	for (int i=n*n;i>=1;i--)
	{
		if (a[i]+b[i]-lx>k||rx-a[i]-b[i]>k||a[i]-b[i]-ly>k||ry-a[i]+b[i]>k) ans[i]=1;
		else lx=min(lx,a[i]+b[i]),rx=max(rx,a[i]+b[i]),ly=min(ly,a[i]-b[i]),ry=max(ry,a[i]-b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (ans[c[i][j]]) cout << "G";
			else cout << "M";
		}
		cout << "\n";
	}
	return 0;
}