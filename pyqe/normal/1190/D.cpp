#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[200069];
map<long long,bool> fq;
map<long long,long long> fw;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i,x,y,z=0,p,lx=0,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].sc,&a[i].fr);
		a[i].fr=-a[i].fr;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		x=a[i].sc;
		y=-a[i].fr;
		if(!fq[x])
		{
			for(p=x;p<=1000000000;p+=p&-p)
			{
				fw[p]++;
			}
			fq[x]=1;
		}
		k=0;
		for(p=x-1;p>0;p-=p&-p)
		{
			k+=fw[p];
		}
		for(p=lx;p>0;p-=p&-p)
		{
			k-=fw[p];
		}
		z-=tri(k);
		if(i==n-1||y!=-a[i+1].fr)
		{
			k=0;
			for(p=1e9;p>0;p-=p&-p)
			{
				k+=fw[p];
			}
			z+=tri(k);
			for(p=x;p>0;p-=p&-p)
			{
				k-=fw[p];
			}
			z-=tri(k);
			lx=0;
		}
		else
		{
			lx=x;
		}
	}
	printf("%lld\n",z);
}