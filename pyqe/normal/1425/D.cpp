#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ma=1000,vy[2069],vx[2069],a[2069],ps[1069][1069],fc[2069],ifc[2069],pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long cb(long long x,long long y)
{
	if(x<y)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

long long qr(long long y,long long x,long long y2,long long x2)
{
	y=max(y,1ll);
	x=max(x,1ll);
	y2=min(y2,ma);
	x2=min(x2,ma);
	if(y>y2||x>x2)
	{
		return 0;
	}
	return ps[y2][x2]-ps[y-1][x2]-ps[y2][x-1]+ps[y-1][x-1];
}

int main()
{
	long long i,j,y,x,y2,x2,c,c2,c3,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&y,&x,a+i);
		vy[i]=y;
		vx[i]=x;
		ps[y][x]++;
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=ma;i++)
	{
		for(j=1;j<=ma;j++)
		{
			ps[i][j]+=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		y=vy[i];
		x=vx[i];
		for(j=1;j<=n;j++)
		{
			y2=vy[j];
			x2=vx[j];
			c=qr(y-d,x-d,y+d,x+d);
			c2=qr(y2-d,x2-d,y2+d,x2+d);
			c3=qr(max(y-d,y2-d),max(x-d,x2-d),min(y+d,y2+d),min(x+d,x2+d));
			z=(z+a[i]*a[j]%dv*(cb(n,m)+dv-cb(n-c,m)+dv-cb(n-c2,m)+cb(n-c-c2+c3,m)))%dv;
		}
	}
	printf("%lld\n",z);
}