#include <bits/stdc++.h>

using namespace std;

long long n,a[19],p10[19];

int main()
{
	long long t,rr,i,j,k,z;
	
	p10[i]=1;
	for(i=1;i<=18;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&n);
		n*=-1;
		for(i=0;i<=18;k/=10,i++)
		{
			a[i]=k%10;
			n+=a[i];
		}
		z=0;
		for(i=0;n>0;i++)
		{
			z+=p10[i+1]-a[i]*p10[i];
			n+=10-a[i];
			a[i]=10;
			for(j=i;a[j]/10;j++)
			{
				n+=1-a[j]/10*10;
				a[j]%=10;
				a[j+1]++;
			}
		}
		printf("%lld\n",z);
	}
}