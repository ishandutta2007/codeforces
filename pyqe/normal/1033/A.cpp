#include <bits/stdc++.h>

using namespace std;

long long n,a[3][2];

int main()
{
	long long i,ii;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		if(a[1][ii]<a[0][ii]^a[2][ii]<a[0][ii])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}