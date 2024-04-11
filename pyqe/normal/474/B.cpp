#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,m,k,z=0,p;
	vector<long long> v;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=k;
		v.push_back(z);
	}
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		p=lower_bound(v.begin(),v.end(),k)-v.begin();
		printf("%lld\n",p+1);
	}
}