#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,y,x,k;
	
	scanf("%lld",&n);
	printf("YES\n");
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&k,&k);
		y=abs(y%2);
		x=abs(x%2);
		printf("%lld\n",y*2+x+1);
	}
}