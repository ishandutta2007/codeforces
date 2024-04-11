#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],fq[200069],ls[200069];

int main()
{
	long long t,i,c=0,mx=0,z=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ls[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		c+=!fq[a[i]];
		fq[a[i]]++;
		mx=max(mx,fq[a[i]]);
		c-=i==ls[a[i]];
		if(!c)
		{
			z+=mx;
			mx=0;
		}
	}
	printf("%lld\n",n-z);
}