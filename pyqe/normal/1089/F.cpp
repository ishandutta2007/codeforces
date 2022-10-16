#include <bits/stdc++.h>

using namespace std;

long long n,fz[2];

void ad(long long x)
{
	fz[0]=x;
	fz[1]=n/x;
}

int main()
{
	long long i,k,w;
	
	scanf("%lld",&n);
	for(k=n,i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			for(w=1;k%i==0;k/=i,w*=i);
			ad(w);
		}
	}
	if(k>1)
	{
		ad(k);
	}
	if(fz[1]<=1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n2\n");
	for(i=1;i<n/fz[0];i++)
	{
		if((n-1-fz[0]*i)%fz[1]==0)
		{
			printf("%lld %lld\n%lld %lld\n",i,fz[1],(n-1-fz[0]*i)/fz[1],fz[0]);
			break;
		}
	}
}