#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n;

ll T;

double a[N],t[N],su,sd;

struct node{
	double x,y;
}o[N];

bool cmp1(node a,node b)
{
	return abs(a.y)<abs(b.y);
}

bool cmp2(node a,node b)
{
	return abs(a.y)>abs(b.y);
}

double sx,sy;

int main()
{
	scanf("%d%lld",&n,&T);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lf",&t[i]),t[i]-=T;
	for(int i=1;i<=n;i++)
		o[i].x=a[i],o[i].y=t[i];
	double ans=0;
	for(int i=1;i<=n;i++)
		if(t[i]>0)
			su+=t[i]*a[i],sx+=a[i];
		else if(t[i]<0)
			sd-=t[i]*a[i],sy+=a[i];
		else 
			ans+=a[i];
	sort(o+1,o+n+1,cmp1);
	if(su==sd)
	{
		printf("%.10lf",sx+sy+ans);
		return 0;
	}
	if(su>sd)
	{
		ans+=sy;
		for(int i=1;i<=n;i++)
			if(o[i].y>0)
			{
				if(sd>o[i].y*o[i].x)
				{
					sd-=o[i].y*o[i].x;
					ans+=o[i].x;
				}
				else
				{
					ans+=sd/o[i].y;
					break;
				}
			}
	}
	else
	{
		ans+=sx;
		for(int i=1;i<=n;i++)
			if(o[i].y<0)
			{
				if(su>-o[i].y*o[i].x)
				{
					su-=-o[i].y*o[i].x;
					ans+=o[i].x;
				}
				else
				{
					ans+=su/-o[i].y;
					break;
				}
			}
	}
	printf("%.10lf",ans);
}

/*
5 3
1 2 3 4 5
5 3 1 4 2

5 10
1 2 3 4 5
5 11 12 20 3
*/