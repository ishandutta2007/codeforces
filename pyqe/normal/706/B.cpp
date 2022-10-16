#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,p,m,k;
	vector<long long> v;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		p=upper_bound(v.begin(),v.end(),k)-v.begin();
		printf("%lld\n",p);
	}
}