#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,c[2]={0,0};
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c[k-1]++;
	}
	printf("%lld\n",max(min(c[0],c[1])+max(c[0]-c[1],0ll)/3,c[0]/3+min(c[0]%3,c[1])));
}