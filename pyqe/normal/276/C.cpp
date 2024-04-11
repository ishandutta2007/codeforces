#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069];

int main()
{
	long long t,rr,i,k,l,z=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		ps[k]++;
		ps[l+1]--;
	}
	for(i=1;i<=n;i++)
	{
		ps[i]+=ps[i-1];
	}
	sort(ps+1,ps+n+1);
	for(i=1;i<=n;i++)
	{
		z+=a[i]*ps[i];
	}
	printf("%lld\n",z);
}