#include <bits/stdc++.h>

using namespace std;

long long n,m;

inline long long qr(long long ky,long long y,long long x)
{
	long long k;
	
	if(ky==1)
	{
		printf("DIG");
	}
	else
	{
		printf("SCAN");
	}
	printf(" %lld %lld\n",y,x);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long t,rr,k,l,sm[2],y,x,y2,x2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		k=qr(2,1,1);
		l=qr(2,1,m);
		sm[0]=(k+l-(m-1)*2)/2+2;
		sm[1]=k-(sm[0]-2)+2;
		k=qr(2,sm[0]/2,1);
		k-=sm[1]-2;
		y=(sm[0]-k)/2;
		y2=sm[0]-y;
		k=qr(2,1,sm[1]/2);
		k-=sm[0]-2;
		x=(sm[1]-k)/2;
		x2=sm[1]-x;
		if(qr(1,y,x))
		{
			qr(1,y2,x2);
		}
		else
		{
			qr(1,y2,x);
			qr(1,y,x2);
		}
	}
}