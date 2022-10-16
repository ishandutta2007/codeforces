#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,t,a[100069],sq,z[100069],c=0;
pair<pair<long long,long long>,long long> qq[100069];
unordered_map<long long,long long> fq;

bool st1(pair<pair<long long,long long>,long long> x,pair<pair<long long,long long>,long long> y)
{
	if((x.fr.fr-1)/sq==(y.fr.fr-1)/sq)
	{
		if(x.fr.sc==y.fr.sc)
		{
			return x.fr.fr<y.fr.fr;
		}
		else
		{
			return x.fr.sc<y.fr.sc;
		}
	}
	else
	{
		return (x.fr.fr-1)/sq<(y.fr.fr-1)/sq;
	}
}

int main()
{
	long long i,lh=1,rh=0;
	
	scanf("%lld%lld",&n,&t);
	sq=sqrt(n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&qq[i].fr.fr,&qq[i].fr.sc);
		qq[i].sc=i;
	}
	sort(qq,qq+t,st1);
	for(i=0;i<t;i++)
	{
		for(;rh<qq[i].fr.sc;)
		{
			rh++;
			fq[a[rh]]++;
			if(fq[a[rh]]==a[rh])
			{
				c++;
			}
			else if(fq[a[rh]]==a[rh]+1)
			{
				c--;
			}
		}
		for(;rh>qq[i].fr.sc;rh--)
		{
			fq[a[rh]]--;
			if(fq[a[rh]]==a[rh])
			{
				c++;
			}
			else if(fq[a[rh]]==a[rh]-1)
			{
				c--;
			}
		}
		for(;lh<qq[i].fr.fr;lh++)
		{
			fq[a[lh]]--;
			if(fq[a[lh]]==a[lh])
			{
				c++;
			}
			else if(fq[a[lh]]==a[lh]-1)
			{
				c--;
			}
		}
		for(;lh>qq[i].fr.fr;)
		{
			lh--;
			fq[a[lh]]++;
			if(fq[a[lh]]==a[lh])
			{
				c++;
			}
			else if(fq[a[lh]]==a[lh]+1)
			{
				c--;
			}
		}
		z[qq[i].sc]=c;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n",z[i]);
	}
}