#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069],ca[200069];

inline bool chk(long long x)
{
	long long i;
	
	nn=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=x)
		{
			nn++;
			ca[nn]=a[i];
		}
	}
	for(i=1;i<nn+1-i;i++)
	{
		if(ca[i]!=ca[nn+1-i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	long long t,rr,i,db;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(db=1;db<n+1-db&&a[db]==a[n+1-db];db++);
		if(db>=n-db+1||chk(a[db])||chk(a[n+1-db]))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}