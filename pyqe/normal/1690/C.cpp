#include <bits/stdc++.h>

using namespace std;

long long n,st[200069],fn[200069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",st+i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",fn+i);
			printf("%lld%c",fn[i]-max(st[i],fn[i-1])," \n"[i==n]);
		}
	}
}