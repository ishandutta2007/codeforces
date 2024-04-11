#include <bits/stdc++.h>

using namespace std;

long long n,m,z=0,a[200069];

int main()
{
	long long i,k,l=-1,kk,ll;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		if(l!=-1)
		{
			kk=min(k,l);
			ll=max(k,l);
			if(kk<ll)
			{
				a[kk]+=kk-1;
				a[ll+1]+=ll-kk*2;
			}
			if(kk+1<ll)
			{
				a[kk+1]-=kk;
				a[ll]-=ll-1-kk*2;
			}
			z+=ll-kk;
		}
		l=k;
	}
	for(i=1;i<=n;i++)
	{
		z+=a[i];
		printf("%lld%c",z," \n"[i==n]);
	}
}