#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long d[5]={1,1,2,7,4},i,k,mn=1e18;
	
	for(i=0;i<5;i++)
	{
		scanf("%lld",&k);
		mn=min(mn,k/d[i]);
	}
	printf("%lld\n",mn);
}