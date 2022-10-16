#include <bits/stdc++.h>

using namespace std;

long long n,m,ln,ti,a[200069],cp[200069],pst[200069],dis[200069],ps[200069];

int main()
{
	long long i,p,sm,z=1e18;
	
	scanf("%lld%lld%lld%lld",&n,&m,&ln,&ti);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,cp+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",pst+i);
	}
	sort(pst+1,pst+m+1);
	m++;
	pst[m]=ln;
	for(i=1;i<=m;i++)
	{
		dis[i]=pst[i]-pst[i-1];
	}
	sort(dis+1,dis+m+1);
	for(i=1;i<=m;i++)
	{
		ps[i]=ps[i-1]+dis[i];
	}
	for(i=1;i<=n;i++)
	{
		if(cp[i]>=dis[m])
		{
			p=upper_bound(dis+1,dis+m+1,cp[i]/2)-dis-1;
			sm=ps[p]+(ps[m]-ps[p])*3-cp[i]*(m-p);
			if(sm<=ti)
			{
				z=min(z,a[i]);
			}
		}
	}
	if(z==1000000000000000000)
	{
		z=-1;
	}
	printf("%lld\n",z);
}