#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,y,x,mx=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&y,&x);
		mx=max(mx,y+x);
	}
	printf("%lld\n",mx);
}