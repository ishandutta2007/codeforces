#include <bits/stdc++.h>

using namespace std;

long long sz=0;
vector<long long> v;

int main()
{
	long long i,k,c;
	
	for(i=4;i<=1003;i++)
	{
		c=0;
		for(k=i;k>0;k/=10)
		{
			c+=k%10;
		}
		if(c%4==0)
		{
			v.push_back(i);
			sz++;
		}
	}
	scanf("%lld",&k);
	printf("%lld\n",v[lower_bound(v.begin(),v.end(),k)-v.begin()]);
}