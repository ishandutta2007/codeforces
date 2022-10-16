#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,mn,z=1;
	
	scanf("%lld%lld",&a,&b);
	mn=min(a,b);
	while(mn>0)
	{
		z*=mn;
		mn--;
	}
	printf("%lld\n",z);
}