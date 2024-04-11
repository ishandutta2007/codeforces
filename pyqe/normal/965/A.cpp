#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long i;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
	}
	printf("%lld\n",(((a[1]-1)/a[2]+1)*a[0]-1)/a[3]+1);
}