#include <bits/stdc++.h>

using namespace std;

long long a[100069];

int main()
{
	long long n,m,i,k,p,sz=0;
	vector<long long> v;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[k]=i;
	}
	for(i=1;i<=100000;i++)
	{
		if(a[i]>0)
		{
			v.push_back(a[i]);
			sz++;
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		p=lower_bound(v.begin(),v.end(),k)-v.begin();
		printf("%lld\n",sz-p);
	}
}