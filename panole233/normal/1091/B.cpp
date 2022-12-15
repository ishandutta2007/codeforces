#include<bits/stdc++.h>
using namespace std;

int n;

struct node
{
	int x,y;
}a[1001],b[1001];

bool cmp(node a,node b) {return a.x<b.x||a.x==b.x&&a.y<b.y;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1; i<=n; i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	printf("%d %d\n",a[1].x+b[n].x,a[1].y+b[n].y);
	return 0;
}