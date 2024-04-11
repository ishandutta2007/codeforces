#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ls[200069];
bitset<200069> vtd,vtd2;

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=vtd[a[i]];
		vtd[a[i]]=1;
		ls[a[i]]=i;
	}
	printf("%lld\n",z);
	for(j=1,i=1;i<=n;i++)
	{
		for(;vtd[j];j++);
		if(vtd2[a[i]]||(j<a[i]&&i<ls[a[i]]))
		{
			a[i]=j;
		}
		else
		{
			vtd2[a[i]]=1;
		}
		vtd[a[i]]=1;
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}