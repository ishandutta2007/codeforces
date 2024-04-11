// Author: Little09
// Problem: E. Capitalism
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N=205,M=2005;
int n,m; 
int a[N],f[N][N],ans=-1,pos;
int fa[N*2];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x!=y) fa[x]=y;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	memset(f,20,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=2*n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		merge(x+n,y),merge(x,y+n);
		if (z==1) f[x][y]=1,f[y][x]=-1;
		else f[x][y]=1,f[y][x]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (find(i)==find(i+n))
		{
			cout << "NO";
			return 0;
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (f[i][i]<0)
		{
			cout << "NO";
			return 0;
		}
		int mx=-n-1;
		for (int j=1;j<=n;j++) mx=max(mx,f[i][j]);
		if (mx>ans) ans=mx,pos=i;
	}
	cout << "YES" << endl;
	cout << ans << endl;
	for (int i=1;i<=n;i++) cout << f[pos][i] << " ";
	return 0;
}