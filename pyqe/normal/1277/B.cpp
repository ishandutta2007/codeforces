#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> mx;

int main()
{
	long long t,rr,i,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx.clear();
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(c=0;k%2==0;k/=2,c++);
			z-=mx[k];
			mx[k]=max(mx[k],c);
			z+=mx[k];
		}
		printf("%lld\n",z);
	}
}