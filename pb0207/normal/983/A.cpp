#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;



int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long g=__gcd(a,b);
		b/=g;
		a/=g; 
		g=__gcd(b,c);
		while(g!=1) 
		{
			while(b%g==0)
				b/=g;
			g=__gcd(b,c);
		}
		if(b!=1)
			puts("Infinite");
		else
			puts("Finite");
	}
}