#include <bits/stdc++.h>

using namespace std;

long long d,a[100069],ps[100069],dv=1e9+7;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld",&t,&d);
	a[0]=1;
	for(i=1;i<=100000;i++)
	{
		a[i]=a[i-1];
		if(i>=d)
		{
			a[i]=(a[i]+a[i-d])%dv;
		}
		ps[i]=(ps[i-1]+a[i])%dv;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",(ps[l]+dv-ps[k-1])%dv);
	}
}