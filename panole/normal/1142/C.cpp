#include<bits/stdc++.h>
using namespace std;

int n,tp,sta[100010];
struct node{long long x,y;}a[100010];

node operator -(node a,node b) {return (node){a.x-b.x,a.y-b.y};}
long long operator ^(node a,node b) {return a.x*b.y-a.y*b.x;}

bool cmp(node a,node b) {return a.x<b.x||a.x==b.x&&a.y<b.y;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%I64d%I64d",&a[i].x,&a[i].y),a[i].y-=a[i].x*a[i].x;
	sort(a+1,a+1+n,cmp),a[n+1].x=10000000,tp=0;
	for (int i=1; i<=n; i++)
		if (a[i].x!=a[i+1].x)
		{
			while (tp>1&&(((a[i]-a[sta[tp]])^(a[sta[tp]]-a[sta[tp-1]]))<=0)) tp--;
			sta[++tp]=i;
		}
	printf("%d\n",tp-1);
	return 0;
}