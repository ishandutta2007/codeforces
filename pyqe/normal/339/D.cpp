#include <bits/stdc++.h>

using namespace std;

long long n,a[18][1<<17];

int main()
{
	long long t,rr,i,j,k,l,p;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<1<<n;i++)
	{
		scanf("%lld",&a[0][i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<1<<n;j+=1<<i)
		{
			if(i%2==1)
			{
				a[i][j]=a[i-1][j]|a[i-1][j+(1<<i-1)];
			}
			else
			{
				a[i][j]=a[i-1][j]^a[i-1][j+(1<<i-1)];
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		p=k-1;
		a[0][p]=l;
		for(i=1;i<=n;i++)
		{
			p-=p%(1<<i);
			if(i%2==1)
			{
				a[i][p]=a[i-1][p]|a[i-1][p+(1<<i-1)];
			}
			else
			{
				a[i][p]=a[i-1][p]^a[i-1][p+(1<<i-1)];
			}
		}
		printf("%lld\n",a[n][0]);
	}
}