#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dv=998244353;
pair<long long,long long> a[300069];

int main()
{
	long long i,ii,z=1,k,c;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	for(i=1;i<=n;i++)
	{
		z=z*i%dv;
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a,a+n);
		k=1;
		for(i=0;i<n;i++)
		{
			if(i==0||a[i].fr!=a[i-1].sc)
			{
				c=0;
			}
			c++;
			k=k*c%dv;
			swap(a[i].fr,a[i].sc);
		}
		z=(z+dv-k)%dv;
	}
	sort(a,a+n);
	k=1;
	for(i=0;i<n;i++)
	{
		if(i==0||a[i]!=a[i-1])
		{
			c=0;
		}
		c++;
		k=k*c%dv;
		if(i>0&&a[i].sc<a[i-1].sc)
		{
			k=0;
		}
	}
	z=(z+k)%dv;
	printf("%lld\n",z);
}