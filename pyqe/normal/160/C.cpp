#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn=0,a[100069];
pair<long long,long long> rg[100069];

int main()
{
	long long i,k,w;
	
	scanf("%lld%lld",&n,&d);
	d--;
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(!i||a[i]!=a[i-1])
		{
			nn++;
			rg[nn]={a[i],0};
		}
		rg[nn].sc++;
	}
	for(i=1;i<=nn;i++)
	{
		k=rg[i].fr;
		w=rg[i].sc;
		if(d<n*w)
		{
			printf("%lld %lld\n",k,a[d/w]);
			break;
		}
		else
		{
			d-=n*w;
		}
	}
}