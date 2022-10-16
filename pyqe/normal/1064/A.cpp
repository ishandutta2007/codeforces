#include <bits/stdc++.h>

using namespace std;

long long a[3];

int main()
{
	long long i;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+3);
	printf("%lld\n",max(a[2]+1-a[1]-a[0],0ll));
}