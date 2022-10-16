#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d=0;
pair<pair<long long,long long>,long long> a[200069];

int main()
{
	long long i,j,k,l,w,p=0,gd,z=0,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[i]={{k,l},w};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(i==n||a[i].fr.fr!=a[i+1].fr.fr)
		{
			if(d&&i-p!=d)
			{
				printf("0\n");
				return 0;
			}
			gd=0;
			for(j=p+1;j<=i;j++)
			{
				gd=__gcd(gd,a[j].sc);
			}
			z=__gcd(z,gd);
			for(j=p+1;j<=i;j++)
			{
				a[j].sc/=gd;
				if(d&&mp(a[j].fr.sc,a[j].sc)!=mp(a[j-p].fr.sc,a[j-p].sc))
				{
					printf("0\n");
					return 0;
				}
			}
			if(!d)
			{
				d=i;
			}
			p=i;
		}
	}
	for(i=1;i*i<=z;i++)
	{
		if(z%i==0)
		{
			c+=1ll+(i!=z/i);
		}
	}
	printf("%lld\n",c);
}