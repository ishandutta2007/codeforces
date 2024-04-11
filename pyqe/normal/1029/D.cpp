#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],wg[200069];
map<long long,long long> fq[11];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(k=a[i];k;k/=10,wg[i]++);
		a[i]%=d;
		fq[wg[i]][a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<=10;j++)
		{
			k=k*10%d;
			z+=fq[j][(d-a[i]*k%d)%d];
			if(j==wg[i])
			{
				z-=a[i]*(k+1)%d==0;
			}
		}
	}
	printf("%lld\n",z);
}