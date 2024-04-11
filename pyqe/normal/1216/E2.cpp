#include <bits/stdc++.h>

using namespace std;

long long a[10],f[10],p10[19];

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,k,i,p,pp,lh,rh,md,z,kk,ppp,zzz,zz;
	
	p10[0]=1;
	for(i=1;i<19;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	for(i=1;i<10;i++)
	{
		f[i]=f[i-1]+9*p10[i-1]*i;
		a[i]=a[i-1]+(9*p10[i-1])*f[i-1]+tri(9*p10[i-1])*i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		p=lower_bound(a,a+9,k)-a;
		lh=p10[p-1]-1;
		rh=p10[p]-1;
		for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
		{
			kk=a[p-1]+(md-p10[p-1]+1)*f[p-1]+tri(md-p10[p-1]+1)*p;
			if(kk>=k)
			{
				rh=md-1;
			}
			else
			{
				zz=kk;
				lh=md+1;
			}
		}
		pp=k-zz;
		for(i=1;i<=9;i++)
		{
			if(pp<=9*p10[i-1]*i)
			{
				z=(pp-1)/i+p10[i-1];
				ppp=i-(pp-1)%i;
				break;
			}
			pp-=9*p10[i-1]*i;
		}
		for(;ppp>1;ppp--,z/=10);
		zzz=z%10;
		printf("%lld\n",zzz);
	}
}