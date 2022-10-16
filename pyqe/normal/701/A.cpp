#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,z=0,d;
	map<long long,queue<long long>> m;
	
	scanf("%lld",&n);
	long long a[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
	}
	d=z/(n/2);
	for(i=1;i<n+1;i++)
	{
		if(m[d-a[i]].empty())
		{
			m[a[i]].push(i);
		}
		else
		{
			printf("%lld %lld\n",m[d-a[i]].front(),i);
			m[d-a[i]].pop();
		}
	}
}