#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k,xr=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		xr^=k;
	}
	if(n%2==0&&xr)
	{
		printf("NO\n");
		return 0;
	}
	n-=n%2==0;
	printf("YES\n%lld\n",n-2);
	for(i=1;i<=(n-2)*2;i+=2)
	{
		for(j=0;j<3;j++)
		{
			printf("%lld%c",min(i,(n-2)*2-i)+j," \n"[j==2]);
		}
	}
}