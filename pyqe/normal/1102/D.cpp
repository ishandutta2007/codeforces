#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],fq[3];

int main()
{
	long long i,j;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
		fq[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(fq[a[i]]>n/3)
		{
			for(j=0;j<a[i];j++)
			{
				if(fq[j]<n/3)
				{
					fq[a[i]]--;
					a[i]=j;
					fq[j]++;
					break;
				}
			}
		}
	}
	for(i=n;i;i--)
	{
		if(fq[a[i]]>n/3)
		{
			for(j=2;j>a[i];j--)
			{
				if(fq[j]<n/3)
				{
					fq[a[i]]--;
					a[i]=j;
					fq[j]++;
					break;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld",a[i]);
	}
	printf("\n");
}