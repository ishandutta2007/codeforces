#include <bits/stdc++.h>

using namespace std;

long long a[100069],f[100069],p10[10];

int main()
{
	long long t,rr,k,i,p,z,pp,ppp,zzz;
	
	p10[0]=1;
	for(i=1;i<10;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	for(i=1;1;i++)
	{
		f[i]=f[i-1];
		for(k=i;k>0;k/=10)
		{
			f[i]++;
		}
		a[i]=a[i-1]+f[i];
		if(a[i]>1000000000)
		{
			break;
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		p=lower_bound(a,a+21837,k)-a;
		pp=k-a[p-1];
		for(i=1;i<=5;i++)
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