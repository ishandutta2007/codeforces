#include <bits/stdc++.h>

using namespace std;

const int d=20;
int n,a[1000069],ps[1000069][d],ls[d],px[1000069],fq[1<<d+1],pf[1<<d+1],vl[21000069];

bool chk(int lh,int rh)
{
	int i,k;
	
	for(i=d-1;i+1;i--)
	{
		k=ps[rh][i]-ps[lh-1][i];
		if(k%2==0&&k==rh-lh+1)
		{
			return 1;
		}
		if(k%2&&k<rh-lh+1)
		{
			return 0;
		}
	}
	return 0;
}

int main()
{
	int i,j,ii,k,mn,mk,p,z=0;
	
	scanf("%d",&n);
	for(i=0;i<=d;i++)
	{
		fq[1<<i]++;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		for(j=0;j<d;j++)
		{
			ps[i][j]=ps[i-1][j]+(a[i]>>j&1);
		}
		px[i]=px[i-1]^a[i];
		for(j=d;j+1;j--)
		{
			fq[1<<d-j|px[i]>>j]++;
		}
	}
	for(i=1;i<1<<d+1;i++)
	{
		pf[i]=pf[i-1]+fq[i];
		fq[i]=0;
	}
	for(i=0;i<=d;i++)
	{
		mk=1<<i;
		fq[mk]++;
		vl[pf[mk-1]+fq[mk]]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=d;j+1;j--)
		{
			mk=1<<d-j|px[i]>>j;
			fq[mk]++;
			vl[pf[mk-1]+fq[mk]]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<d;j++)
		{
			if(!(a[i]>>j&1))
			{
				ls[j]=i;
			}
		}
		mn=i;
		for(j=d;j;j--)
		{
			mk=1<<d-j|px[i]>>j;
			p=lower_bound(vl+pf[mk-1]+1,vl+pf[mk]+1,ls[j-1])-vl;
			for(ii=0;ii<2;ii++)
			{
				if(p+ii<=pf[mk])
				{
					k=vl[p+ii];
					if(k<mn&&chk(k+1,i))
					{
						z=max(z,i-k);
					}
				}
			}
			mn=min(mn,ls[j-1]);
		}
	}
	printf("%d\n",z);
}