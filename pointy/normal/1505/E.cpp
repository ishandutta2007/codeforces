#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
char a[10][10];
struct point
{
	int x,y;
}p[30];
bool work(int &x,int &y)
{
	int u=-1;
	for (int i=1;i<=cnt;i++)
	{
		if (x>p[i].x||y>p[i].y) continue;
		if (u==-1||p[i].x+p[i].y<p[u].x+p[u].y) u=i;
	}
	if (u==-1) return 1;
	ans++;
	x=p[u].x,y=p[u].y;
	p[u].x=0,p[u].y=0;
	return 0;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			if (a[i][j]=='*') p[++cnt].x=i,p[cnt].y=j;
		}
	}
	int X=1,Y=1;
	while (1) if (work(X,Y)) break;
	cout << ans;
	return 0;
}