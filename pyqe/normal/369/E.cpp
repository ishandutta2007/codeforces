#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sz=0,z[300069],fw[1000069];
pair<long long,long long> a[300069];
pair<pair<long long,long long>,long long> qq[600069];

int main()
{
	long long i,j,t,d,k,l,w,p,v;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].sc,&a[i].fr);
	}
	sort(a,a+n);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&d);
		l=0;
		for(j=0;j<=d;j++)
		{
			if(j<d)
			{
				scanf("%lld",&k);
			}
			else
			{
				k=1e6+1;
			}
			qq[sz]=mp(mp(k,l),i);
			sz++;
			l=k;
		}
		z[i]=n;
	}
	sort(qq,qq+sz);
	j=0;
	for(i=0;i<sz;i++)
	{
		k=qq[i].fr.fr;
		l=qq[i].fr.sc;
		w=qq[i].sc;
		for(;j<n&&a[j].fr<k;j++)
		{
			for(p=a[j].sc;p<=1000000;p+=p&-p)
			{
				fw[p]++;
			}
		}
		v=j;
		for(p=l;p>0;p-=p&-p)
		{
			v-=fw[p];
		}
		z[w]-=v;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n",z[i]);
	}
}