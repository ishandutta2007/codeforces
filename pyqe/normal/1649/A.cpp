#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]=k;
		}
		for(i=1;i<n&&a[i+1];i++);
		mn=i;
		for(i=n;i>1&&a[i-1];i--);
		mx=i;
		printf("%lld\n",max(mx-mn,0ll));
	}
}