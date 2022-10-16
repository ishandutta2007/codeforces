#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[4];

int main()
{
	long long i,ii,k;
	char ch;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			a[i]|=k<<ii;
			if(ii)
			{
				fq[a[i]]++;
			}
		}
	}
	printf("%lld\n",fq[0]*fq[3]+fq[1]*fq[2]+fq[0]*fq[1]);
}