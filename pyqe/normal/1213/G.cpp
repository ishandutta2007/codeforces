#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,t,pr[200069],z[200069],cd[200069];
pair<long long,pair<long long,long long>> a[200069];
pair<long long,long long> qq[200069];

long long tri(long long x)
{
	return x*(x-1)/2;
}

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long i,j,k,l,w,pz,sm=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&a[i].sc.fr,&a[i].sc.sc,&a[i].fr);
	}
	sort(a,a+n-1);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&qq[i].fr);
		qq[i].sc=i;
	}
	sort(qq,qq+t);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
		cd[i]=1;
	}
	j=0;
	for(i=0;i<t;i++)
	{
		w=qq[i].fr;
		pz=qq[i].sc;
		for(;j<n-1&&a[j].fr<=w;j++)
		{
			k=a[j].sc.fr;
			l=a[j].sc.sc;
			if(fd(k)!=fd(l))
			{
				sm+=tri(cd[fd(k)]+cd[fd(l)])-tri(cd[fd(k)])-tri(cd[fd(l)]);
				cd[fd(k)]+=cd[fd(l)];
				pr[fd(l)]=fd(k);
			}
		}
		z[pz]=sm;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld%c",z[i]," \n"[i==t-1]);
	}
}