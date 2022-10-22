#include<bits/stdc++.h>
using namespace std;

int T;

char s[111];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long t=(c+b-1)/b*b;
		printf("%lld %lld %lld\n",a+t,b,c);
	}
}