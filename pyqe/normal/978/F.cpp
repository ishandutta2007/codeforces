#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[200069];
pair<long long,long long> a[200069];

int main()
{
	long long i,j,k,l,w;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(a[k].fr!=a[l].fr)
		{
			if(a[k].fr<a[l].fr)
			{
				swap(k,l);
			}
			sq[k]--;
		}
	}
	sort(a+1,a+n+1);
	for(j=0,i=1;i<=n;i++)
	{
		k=a[i].sc;
		w=a[i].fr;
		for(;j<n&&a[j+1].fr<w;j++);
		sq[k]+=j;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}