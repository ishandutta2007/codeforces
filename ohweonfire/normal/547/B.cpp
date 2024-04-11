#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;

int n,a[maxn],ans[maxn],ord[maxn];

int f[maxn],sz[maxn],mxsz;
int gf(int x)
{
	if(f[x]==x)return x;
	return f[x]=gf(f[x]);
}
void U(int x,int y)
{
	x=gf(x);
	y=gf(y);
	f[y]=x;
	if(x!=y)sz[x]+=sz[y];
	mxsz=max(mxsz,sz[x]);
}

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		f[i]=i;
		sz[i]=1;
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	for(int _=1,i;_<=n;_++)
	{
		i=ord[_];
		int tmp=mxsz;
		if(i!=1&&a[i]<=a[i-1])U(i-1,i);
		if(i!=n&&a[i]<=a[i+1])U(i,i+1);
		if(mxsz==0)mxsz=1;
		for(int j=tmp+1;j<=mxsz;j++)ans[j]=a[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}