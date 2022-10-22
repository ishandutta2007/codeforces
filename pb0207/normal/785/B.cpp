#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int l,r;
}a[N],b[N];

int n,m,ans;

bool cmpl(node a,node b)
{
	return a.l<b.l;
}

bool cmpr(node a,node b)
{
	return a.r<b.r;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	cin>>m;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+n+1,cmpl);
	sort(b+1,b+m+1,cmpr);
	if(a[n].l>b[1].r)
		ans=max(ans,a[n].l-b[1].r);
	sort(a+1,a+n+1,cmpr);
	sort(b+1,b+m+1,cmpl);
	if(a[1].r<b[m].l)
		ans=max(ans,b[m].l-a[1].r);
	cout<<ans;
}