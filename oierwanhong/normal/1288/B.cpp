#include <bits/stdc++.h>
typedef long long ll;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll A,B,x=9,cnt=0;
		scanf("%lld%lld",&A,&B);
		while(x<=B)x=x*10+9,++cnt;
		printf("%lld\n",A*cnt);
	}
	
	return 0;
}