#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pst[100069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pst[a[i]]=i;
		}
		for(i=1;i<=n&&a[i]==i;i++);
		if(i<=n)
		{
			k=i;
			for(i=k;i<pst[k]-(i-k);i++)
			{
				swap(a[i],a[pst[k]-(i-k)]);
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}