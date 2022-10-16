#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],wg[100069],ps[100069],sx[100069],inf=1e18;

int main()
{
	long long i,w=inf,mn=inf,z[3]={0,0,0};
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	sx[n+1]=0;
	for(i=n;i;i--)
	{
		sx[i]=max(sx[i+1],ps[n]-ps[i-1]-wg[i]);
	}
	z[0]=sx[1];
	for(i=1;i<n;i++)
	{
		mn=min(mn,wg[i]);
		z[1]=max(z[1],sx[i+1]+max(ps[i]-mn,0ll));
		if(i-1)
		{
			w=min(w,min(a[i],wg[i]));
		}
	}
	z[1]=max(z[1],ps[n]-wg[1]-w);
	z[2]=max(z[2],max(ps[n]-mn,a[n]-wg[n]));
	printf("%lld\n",z[min(d,2ll)]);
}