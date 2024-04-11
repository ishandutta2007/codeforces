#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

struct node
{
	int a,b;
	long long h;
}a[100001];

struct node2
{
	int x,ord;
}x[200001];

int n,l,r,mid,last;
long long ans,f[100001],tree[200001];

bool cmp(node a,node b) {return a.b<b.b||a.b==b.b&&a.a<b.a;}
bool cmp2(node2 a,node2 b) {return a.x<b.x;}
int lowbit(int x) {return x&-x;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d%I64d",&a[i].a,&a[i].b,&a[i].h);
	for (int i=1; i<=n; i++)
		x[(i<<1)-1].x=a[i].a,x[i<<1].x=a[i].b,x[(i<<1)-1].ord=(i<<1)-1,x[i<<1].ord=(i<<1);
	sort(x+1,x+1+n*2,cmp2);
	x[0].x=-2147483647; last=1;
	for (int i=1; i<=n*2; i++)
		if (x[i].ord&1)
		{ 
			if (x[i].x==x[i-1].x) a[(x[i].ord+1)/2].a=last;
			else a[(x[i].ord+1)/2].a=i,last=i;
		}
		else 
		{
			if (x[i].x==x[i-1].x) a[x[i].ord/2].b=last;
			else a[x[i].ord/2].b=i,last=i;
		}
	sort(a+1,a+1+n,cmp);
	memset(f,0,sizeof(f));
	f[n]=a[n].h;
	memset(tree,0,sizeof(tree));
	for (int i=a[n].a; i<=200000; i+=lowbit(i)) tree[i]=max(tree[i],a[n].h);
	for (int i=n-1; i>=1; i--)
	{
		for (int j=a[i].b-1; j>=1; j-=lowbit(j)) f[i]=max(f[i],tree[j]+a[i].h);
		for (int j=a[i].a; j<=200000; j+=lowbit(j)) tree[j]=max(tree[j],f[i]);
	}
	ans=0;
	for (int i=1; i<=n; i++) ans=max(ans,f[i]);
	printf("%I64d\n",ans);
	return 0;
}