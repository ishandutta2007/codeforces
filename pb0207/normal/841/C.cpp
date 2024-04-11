#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],b[N],id[N],ans[N];

struct node{
	int x,id;
}t[N];

bool cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),t[i].id=i,t[i].x=b[i];
	sort(t+1,t+n+1,cmp);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans[t[i].id]=a[n-i+1];
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}