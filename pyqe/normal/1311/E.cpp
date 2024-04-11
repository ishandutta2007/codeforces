#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],dh[100069],pr[100069];

int main()
{
	long long t,rr,i,j,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		dh[1]=0;
		a[0]=1;
		mx=0;
		for(i=2;i<=n;i++)
		{
			pr[i]=i/2;
			dh[i]=dh[pr[i]]+1;
			if(dh[i-1]<dh[i])
			{
				a[dh[i]]=i;
			}
			d-=dh[i];
			mx=dh[i];
		}
		if(d<0)
		{
			printf("NO\n");
			continue;
		}
		for(i=n;i-1;i--)
		{
			if(a[dh[i]]!=i)
			{
				k=min(mx+1-dh[i],d);
				if(k)
				{
					dh[i]+=k;
					pr[i]=a[dh[i]-1];
					d-=k;
				}
				if(dh[i]>mx)
				{
					a[dh[i]]=i;
					mx=dh[i];
				}
			}
		}
		if(!d)
		{
			printf("YES\n");
			for(i=2;i<=n;i++)
			{
				printf("%lld%c",pr[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}