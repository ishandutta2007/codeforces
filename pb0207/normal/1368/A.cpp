#include<bits/stdc++.h>
using namespace std;

int T;

long long a,b,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		if(a>b)
			swap(a,b);
		long long ans=0;
		while(b<=n)
		{
			a+=b;
			swap(a,b);
			ans++;
		}
		printf("%lld\n",ans);
	}
}