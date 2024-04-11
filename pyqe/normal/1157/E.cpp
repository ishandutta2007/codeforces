#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
multiset<long long> ms;
multiset<long long>::iterator it;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		ms.insert(k);
		ms.insert(k+n);
	}
	for(i=0;i<n;i++)
	{
		it=ms.lower_bound((n-a[i])%n);
		k=*it%n;
		a[i]=(a[i]+k)%n;
		ms.erase(ms.find(k));
		ms.erase(ms.find(k+n));
		printf("%lld%c",a[i]," \n"[i==n-1]);
	}
}