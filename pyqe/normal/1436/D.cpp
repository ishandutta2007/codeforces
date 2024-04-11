#include <bits/stdc++.h>

using namespace std;

int n,pr[200069],aa[200069],a[200069],dsu[200069];
long long ub=2e14;
bitset<200069> spc;

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	int i,w,p;
	long long k,lh,rh,md,zz;
	
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",pr+i);
		spc[pr[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",aa+i);
	}
	for(lh=0,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
			a[i]=aa[i];
		}
		for(i=1;i<=n;i++)
		{
			if(!spc[i])
			{
				for(k=md,p=fd(i);k&&p;)
				{
					w=min(k,(long long)a[p]);
					k-=w;
					a[p]-=w;
					if(!a[p])
					{
						dsu[p]=fd(pr[p]);
						p=fd(p);
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[i])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}