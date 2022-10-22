#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=3e5+1e3+7;

int n;

struct DATA{
	int x,id;
}a[N];

bool cmp(DATA a,DATA b)
{
	return a.x<b.x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int mxd=a[n].id,mnd=a[n].id,k=0x7fffffff;
	for(int i=n-1;i>=1;i--)
	{
		int dsm=max(abs(mxd-a[i].id),abs(mnd-a[i].id));
		mxd=max(mxd,a[i].id);
		mnd=min(mnd,a[i].id);
		k=min(k,a[i].x/dsm);
	}
	printf("%d",k);
}