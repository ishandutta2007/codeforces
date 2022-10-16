#include <bits/stdc++.h>

using namespace std;

long long n,p10[13];

int main()
{
	long long i,dg,k,tg,rm;
	
	p10[0]=1;
	for(i=1;i<=12;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	scanf("%lld",&n);
	for(dg=1;1;dg++)
	{
		k=p10[dg-1]*9*dg;
		if(n<=k)
		{
			break;
		}
		n-=k;
	}
	tg=(n-1)/dg+p10[dg-1];
	rm=dg-(n-1)%dg;
	printf("%lld\n",tg/p10[rm-1]%10);
}