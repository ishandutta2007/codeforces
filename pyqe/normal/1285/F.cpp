#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e5;
long long n,nn=0,ps[2000069],pfq[100069];
vector<pair<long long,long long>> ex[100069];
bitset<100069> fq,ca;

int main()
{
	long long i,j,r,u,k,sz,p,sm,mx,lh,rh,md,zz,z=0;
	
	for(i=1;i<=ma;i++)
	{
		ex[i].push_back({1,1});
	}
	for(i=2;i<=ma;i++)
	{
		sz=ex[i].size();
		if(sz==1)
		{
			for(j=i;j<=ma;j+=i)
			{
				sz=ex[j].size();
				for(r=0;r<sz;r++)
				{
					k=ex[j][r].fr;
					u=ex[j][r].sc;
					ex[j].push_back({k*i,-u});
				}
			}
		}
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z=max(z,k);
		fq[k]=1;
	}
	for(i=1;i<=ma;i++)
	{
		nn=0;
		for(j=i;j<=ma;j+=i)
		{
			nn++;
			ca[nn]=fq[j];
		}
		for(j=1;j<=nn;j++)
		{
			pfq[j]=pfq[j-1];
			sm=0;
			for(r=j;r<=nn;r+=j)
			{
				sm+=ca[r];
				pfq[j]++;
				ps[pfq[j]]=sm;
			}
		}
		mx=0;
		for(j=1;j<=nn;j++)
		{
			if(ca[j])
			{
				sz=ex[j].size();
				for(zz=-1,lh=j+1,rh=nn;lh<=rh;)
				{
					md=(lh+rh)/2;
					sm=0;
					for(r=0;r<sz;r++)
					{
						k=ex[j][r].fr;
						u=ex[j][r].sc;
						sm+=ps[pfq[k]]*u;
						p=(md-1)/k;
						if(p)
						{
							sm-=ps[pfq[k-1]+p]*u;
						}
					}
					if(sm)
					{
						zz=md;
						lh=md+1;
					}
					else
					{
						rh=md-1;
					}
				}
				if(zz!=-1)
				{
					mx=max(mx,j*zz);
				}
			}
		}
		z=max(z,mx*i);
	}
	printf("%lld\n",z);
}