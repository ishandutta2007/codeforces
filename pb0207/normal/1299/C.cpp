#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1e3+7;

int n;

long long a[N],s[N];

int q[N],tail,head;

struct P{
	long long x,y;
	int id;
	P(long long _x=0,long long _y=0){x=_x,y=_y;}
}p[N];

P operator -(P a,P b)
{
	return P(a.x-b.x,a.y-b.y);
}

long long cross(P a,P b)
{
	return a.x*b.y-a.y*b.x;
}

double ans[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i],p[i].x=i,p[i].y=s[i];
	for(int i=0;i<=n;i++)
	{
		while(tail>=2&&cross(p[q[tail]]-p[q[tail-1]],p[i]-p[q[tail-1]])<=0)
			tail--;
		q[++tail]=i;
	}
	for(int i=2;i<=tail;i++)
	{
		double sum=0;
		for(int j=q[i-1]+1;j<=q[i];j++)
			sum+=a[j];
		sum/=q[i]-q[i-1];
		for(int j=q[i-1]+1;j<=q[i];j++)
			ans[j]=sum;
	}
	for(int i=1;i<=n;i++)
		printf("%.12lf\n",ans[i]);
}