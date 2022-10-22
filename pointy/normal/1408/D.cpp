#include<bits/stdc++.h>
using namespace std;
int n,m,ans=2100000000; 
struct qooo
{
	int x,y;
}q[4200001],a[2001],b[2001];
bool cmp(qooo x,qooo y)
{
	return x.x>y.x;
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	for (int i=1;i<=m;i++)
	{
		cin >> b[i].x >> b[i].y;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			qooo u;
			if (a[i].x>b[j].x) continue;
			u.x=b[j].x-a[i].x+1;
			if (a[i].y>b[j].y) continue;
			u.y=b[j].y-a[i].y+1;
			q[++cnt]=u;
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int maxy=0;
	for (int i=1;i<=cnt;i++)
	{
		ans=min(ans,q[i].x+maxy);
		maxy=max(maxy,q[i].y);
	}
	ans=min(ans,maxy);
	cout << ans;
	return 0;
}