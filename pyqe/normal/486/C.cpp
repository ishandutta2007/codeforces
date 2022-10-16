#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,k,mn,mx=0,sm=0;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	d=min(d,n+1-d);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	mn=n+1;
	for(i=1;i<n+1-i;i++)
	{
		k=abs(a[i]-a[n+1-i]);
		k=min(k,26-k);
		sm+=k;
		if(k)
		{
			mn=min(mn,i);
			mx=i;
		}
	}
	mn=min(mn,d);
	mx=max(mx,d);
	printf("%lld\n",sm+mx-mn+min(d-mn,mx-d));
}