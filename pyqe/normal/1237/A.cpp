#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	bool u=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k%2==0)
		{
			printf("%lld\n",k/2);
		}
		else
		{
			printf("%lld\n",((k+10000)/2-5000)+u);
			u=!u;
		}
	}
}