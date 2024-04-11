#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l,ee;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		ee=k>l;
		if(ee)
		{
			swap(k,l);
		}
		if(l>k*3+1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=2;i<=k+k;i+=2)
		{
			printf("%lld %lld\n",3+ee,i);
		}
		for(i=1;l&&i<=k+k+1;i+=2,l--)
		{
			printf("%lld %lld\n",3+ee,i);
		}
		for(i=2;l&&i<=k+k;i+=2,l--)
		{
			printf("%lld %lld\n",2+ee,i);
		}
		for(i=2;l&&i<=k+k;i+=2,l--)
		{
			printf("%lld %lld\n",4+ee,i);
		}
	}
}