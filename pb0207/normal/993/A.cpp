#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

struct P{
	int x,y;
}p[N],q[N];

int cross(P a,P b)
{
	return a.x*b.y-a.y*b.x;
}

P operator -(P a,P b)
{
	P ret;
	ret.x=a.x-b.x;
	ret.y=a.y-b.y;
	return ret;
}

bool chk1(P *a,P *b)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(cross(a[j+1]-a[j],a[j+1]-b[i])>0)
				return false;
	return true;
}

bool chk2(P a,P b,P c,P d)
{
	P f=a-b,g=c-d;
	return (cross(c-a,f)*cross(f,d-a)>=0)&&(cross(a-c,g)*cross(g,b-c)>=0);
}

void rev(P *a)
{
	if(cross(a[1]-a[0],a[2]-a[1])<0)
		reverse(a+0,a+5);
}

int main()
{
	for(int i=0;i<4;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=0;i<4;i++)
		scanf("%d%d",&q[i].x,&q[i].y);
	p[4]=p[0],q[4]=q[0];
	rev(p),rev(q);
	bool flag=false;
	flag|=chk1(p,q)|chk1(q,p);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			flag|=chk2(p[i],p[i+1],q[j],q[j+1]);
	puts(flag?"Yes":"No");
}