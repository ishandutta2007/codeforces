#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn,pst[200069],ps[200069];
bitset<200069> a;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&m);
		for(i=1;i<=n;i++)
		{
			a[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			a[k]=1;
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(!a[i])
			{
				nn++;
				pst[nn]=i;
			}
			ps[i]=ps[i-1]+a[i];
		}
		if(nn%(d-1)==0&&ps[pst[nn-d/2+1]-1]-ps[pst[d/2]])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}