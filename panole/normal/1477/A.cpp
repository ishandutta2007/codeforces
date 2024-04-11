#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	return (!b)?a:gcd(b,a%b);
}

int n,T;
long long k, a[200010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld",&n,&k);
		for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
		long long g=0;
		if (n==1) 
		{
			if (a[1]==k) puts("YES");
			else puts("NO");
			continue;
		}
		for (int i=2 ;i<=n; i++) g=gcd(g,abs(a[i]-a[1]));
		
		if ((k%g+g)%g==(a[1]%g+g)%g) puts("YES"); else puts("NO");
	}
	return 0;
}