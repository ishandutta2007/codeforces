#include <bits/stdc++.h>

using namespace std;

long long n,a[169],pst[169];

int main()
{
	long long t,rr,mx,ls,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pst[a[i]]=i;
		}
		mx=1;
		for(i=1;i<=n;i++)
		{
			for(ls=mx;a[ls]<i;ls++);
			for(;pst[i]>ls;)
			{
				mx=max(mx,pst[i]);
				k=pst[i]-1;
				l=pst[i];
				swap(a[k],a[l]);
				swap(pst[a[k]],pst[a[l]]);
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}