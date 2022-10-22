#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int T;
 
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		int e=a+b+c+d;
		if (e%3!=0)
		{
			printf("NO\n");
			continue;
		}
		e/=3;
		if (e>=a&&e>=b&&e>=c)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}