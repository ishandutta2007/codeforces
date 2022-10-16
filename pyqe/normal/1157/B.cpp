#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ky[10];

int main()
{
	long long i,c=0,z;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
	}
	for(i=1;i<=9;i++)
	{
		scanf("%lld",ky+i);
	}
	for(i=1;i<=n;i++)
	{
		if(!c&&ky[a[i]]>a[i])
		{
			c++;
		}
		else if(c==1&&a[i]>ky[a[i]])
		{
			c++;
		}
		if(c%2==0)
		{
			z=a[i];
		}
		else
		{
			z=ky[a[i]];
		}
		printf("%lld",z);
	}
	printf("\n");
}