#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pr[2][100069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i>0;i--)
	{
		if(i==n||a[i]>a[i+1])
		{
			pr[0][i]=i;
		}
		else
		{
			pr[0][i]=pr[0][i+1];
		}
	}
	for(i=n;i>0;i--)
	{
		if(i==n||a[i]<a[i+1])
		{
			pr[1][i]=i;
		}
		else
		{
			pr[1][i]=pr[1][i+1];
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(pr[1][pr[0][k]]>=l)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}