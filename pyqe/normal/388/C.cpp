#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[169];

int main()
{
	long long i,j,k,sz,z[2]={0,0};
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		for(j=1;j<=sz;j++)
		{
			scanf("%lld",&k);
			if(j<=sz/2)
			{
				z[0]+=k;
			}
			else if(j>(sz+1)/2)
			{
				z[1]+=k;
			}
			else
			{
				nn++;
				a[nn]=k;
			}
		}
	}
	sort(a+1,a+nn+1,greater<long long>());
	for(i=1;i<=nn;i++)
	{
		z[(i-1)%2]+=a[i];
	}
	printf("%lld %lld\n",z[0],z[1]);
}