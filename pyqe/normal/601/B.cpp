#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,a[100069];
pair<long long,long long> sk[100069];

int main()
{
	long long t,rr,i,k,l=-1,z;
	
	scanf("%lld%lld",&n,&t);
	n--;
	for(i=0;i<=n;i++)
	{
		scanf("%lld",&k);
		if(l+1)
		{
			a[i]=abs(k-l);
		}
		l=k;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		l--;
		z=0;
		nn=0;
		sk[0].fr=k-1;
		for(i=k;i<=l;i++)
		{
			for(;nn&&a[i]>=sk[nn].sc;nn--)
			{
				z+=(a[i]-sk[nn].sc)*(sk[nn].fr-sk[nn-1].fr)*(l+1-i);
			}
			z+=a[i]*(l+1-i);
			nn++;
			sk[nn]={i,a[i]};
		}
		printf("%lld\n",z);
	}
}