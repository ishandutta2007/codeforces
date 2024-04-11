#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069];

int main()
{
	long long t,rr,i,j,k,l;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			if(!i||k!=l)
			{
				nn++;
				a[nn]=0;
			}
			a[nn]++;
			l=k;
		}
		for(j=1,i=1;i<=nn;i++)
		{
			for(j=max(j,i);j<=nn&&a[j]<=1;j++);
			if(j<=nn)
			{
				a[j]--;
			}
			else
			{
				break;
			}
		}
		printf("%lld\n",i-1+(nn+1-i+1)/2);
	}
}