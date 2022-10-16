#include <bits/stdc++.h>

using namespace std;

long long n,a[2][569];
pair<long long,long long> as[2][569];

int main()
{
	long long t,rr,i,ii,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
			for(i=1;i<n+1-i;i++)
			{
				k=a[ii][i];
				l=a[ii][n+1-i];
				if(k>l)
				{
					swap(k,l);
				}
				as[ii][i]={k,l};
			}
			sort(as[ii]+1,as[ii]+n/2+1);
		}
		for(i=1;i<=n/2;i++)
		{
			if(as[0][i]!=as[1][i])
			{
				i=-1;
				break;
			}
		}
		if(i==-1||(n%2&&a[0][(n+1)/2]!=a[1][(n+1)/2]))
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}