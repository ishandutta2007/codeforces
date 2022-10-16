#include <bits/stdc++.h>

using namespace std;

int n,ma=2e5,af=1<<18,fq[1<<18],dsu[200069];

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
	int i,k,l,mk,mkk;
	long long z=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		fq[k]++;
		z-=k;
	}
	fq[0]++;
	for(i=0;i<=ma;i++)
	{
		dsu[i]=i;
	}
	for(mk=af-1;mk;mk--)
	{
		for(mkk=mk;mkk>(mk^mkk);mkk=mkk-1&mk)
		{
			if(fq[mkk]&&fq[mk^mkk])
			{
				k=fd(mkk);
				l=fd(mk^mkk);
				if(k!=l)
				{
					z+=(long long)mk*(fq[mkk]+fq[mk^mkk]-1);
					dsu[l]=k;
					fq[k]=1;
					fq[l]=1;
				}
				
			}
		}
	}
	printf("%lld\n",z);
}