#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[30],zs=0;

int main()
{
	long long i,j,ii,k;
	
	scanf("%lld%lld",&n,&d);
	if(d>n)
	{
		printf("NO\n");
		return 0;
	}
	for(i=29;i+1;i--)
	{
		if(n>>i&1)
		{
			fq[i]++;
			zs++;
		}
	}
	if(zs>d)
	{
		printf("NO\n");
		return 0;
	}
	for(i=29;zs<d;zs++)
	{
		for(;!fq[i];i--);
		fq[i]--;
		fq[i-1]+=2;
	}
	printf("YES\n");
	for(i=0;i<30;i++)
	{
		for(j=0;j<fq[i];j++)
		{
			zs--;
			printf("%lld%c",1ll<<i," \n"[!zs]);
		}
	}
}