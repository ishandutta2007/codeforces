#include <bits/stdc++.h>

using namespace std;

long long n,m,ps[1000069];
bitset<1000069> a;

int main()
{
	long long t,rr,i,j,k,l,p;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			p=(i-1)*m+j;
			scanf(" %c",&ch);
			a[p]=ch=='X';
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=2;j<=m;j++)
		{
			p=(i-1)*m+j;
			ps[j]|=a[p]&&a[p+m-1];
		}
	}
	for(i=1;i<=m;i++)
	{
		ps[i]+=ps[i-1];
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(ps[l]-ps[k]==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}