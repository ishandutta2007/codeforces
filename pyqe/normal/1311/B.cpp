#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],pr[100069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pr[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			pr[k]=k+1;
		}
		for(i=n;i;i--)
		{
			pr[i]=pr[pr[i]];
		}
		for(i=1;i<=n;i=pr[i]+1)
		{
			sort(a+i,a+pr[i]+1);
		}
		for(i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}