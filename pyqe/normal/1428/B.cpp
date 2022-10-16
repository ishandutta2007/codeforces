#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],fq[2];

int main()
{
	long long t,rr,i,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			a[i]=(ch=='>')-(ch=='-');
			if(a[i]!=-1)
			{
				fq[a[i]]++;
			}
		}
		z=0;
		for(i=0;i<n;i++)
		{
			z+=a[i]==-1||a[(i+n-1)%n]==-1||!fq[0]||!fq[1];
		}
		printf("%lld\n",z);
	}
}