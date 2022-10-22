#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

const double eps=1e-6,pi=acos(-1);

struct P{
	double x,y;
	P(double _x=0,double _y=0){x=_x,y=_y;}
}p[N];

P operator -(P a,P b)
{
	return P(a.x-b.x,a.y-b.y);
}

double operator *(P a,P b)
{
	return a.x*b.x+a.y*b.y;
}

double cal(P a,P b)
{
	return acos(a*b/(a*a)/(b*b));
}

bool chk(P a,P b,P c)
{
	double ang1=pi-cal(a,b);
	double ang2=pi-cal(b,c);
	return fabs(ang1+ang2-pi)<eps;
}

int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	if(n&1)
		puts("NO");
	else
	{
		double xc=p[1].x+p[n/2+1].x;
		double yc=p[1].y+p[n/2+1].y;
		bool ans=1;
		for(int i=2;i<=n/2;i++)
			ans&=(p[i].x+p[n/2+i].x==xc)&&(p[i].y+p[n/2+i].y==yc);
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
}