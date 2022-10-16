#include <bits/stdc++.h>

using namespace std;

const int sqn=447;
int n,a[200069],a2[200069],fq[469][469],lz[200069],ls[200069];

int main()
{
	int t,rr,i,ky,k,w,sm,z;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,a2+i);
	}
	sm=0;
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d%d",&ky,&k);
		w=a[k]+a2[k];
		sm+=lz[rr];
		if(ky==1)
		{
			if(w<=sqn)
			{
				for(i=a[k];i<w;i++)
				{
					fq[w][(i+rr)%w]++;
				}
			}
			else
			{
				for(i=rr;i+a[k]<=t;i+=w)
				{
					lz[i+a[k]]++;
					if(i+w<=t)
					{
						lz[i+w]--;
					}
				}
			}
			ls[k]=rr;
		}
		else
		{
			if(w<=sqn)
			{
				for(i=a[k];i<w;i++)
				{
					fq[w][(i+ls[k])%w]--;
				}
			}
			else
			{
				sm-=(rr-ls[k])%w>=a[k];
				for(i=ls[k];i+a[k]<=t;i+=w)
				{
					lz[i+a[k]]--;
					if(i+w<=t)
					{
						lz[i+w]++;
					}
				}
			}
		}
		z=sm;
		for(i=1;i<=sqn;i++)
		{
			z+=fq[i][rr%i];
		}
		printf("%d\n",z);
	}
}