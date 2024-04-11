#include <bits/stdc++.h>

using namespace std;

long long n,ub[3]={1414213562,1259921,37606},a[569],nn=0,ex[1069],dv=998244353;
map<long long,bool> vtd;

void ad(long long x)
{
	nn++;
	ex[nn]=x;
	vtd[x]=1;
}

int main()
{
	long long i,j,r,ii,k,w,lh,rh,md,zz,c,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=4;j>=2;j--)
		{
			zz=-1;
			for(lh=1,rh=ub[j-2];lh<=rh;)
			{
				md=(lh+rh)/2;
				w=1;
				for(r=0;r<j;r++)
				{
					w*=md;
				}
				if(w==a[i])
				{
					zz=md;
					break;
				}
				else if(w<a[i])
				{
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			if(zz!=-1)
			{
				break;
			}
		}
		if(zz!=-1)
		{
			if(!vtd[zz])
			{
				ad(zz);
			}
			continue;
		}
		for(j=1;j<=n;j++)
		{
			k=__gcd(a[i],a[j]);
			if(k!=1&&k!=a[i])
			{
				if(!vtd[k])
				{
					ad(k);
				}
				if(!vtd[a[i]/k])
				{
					ad(a[i]/k);
				}
				break;
			}
		}
		if(j<=n)
		{
			continue;
		}
		if(!vtd[a[i]])
		{
			for(ii=0;ii<2;ii++)
			{
				ad(a[i]);
			}
		}
	}
	for(i=1;i<=nn;i++)
	{
		c=0;
		for(j=1;j<=n;j++)
		{
			for(k=a[j];k%ex[i]==0;k/=ex[i],c++);
		}
		z=z*(c+1)%dv;
	}
	printf("%lld\n",z);
	fflush(stdout);
}