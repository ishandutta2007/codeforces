#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,a[3];
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+3);
	printf("%lld\n",min((a[0]+a[1]+a[2])/3,a[0]+a[1]));
}