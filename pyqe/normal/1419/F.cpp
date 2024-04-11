#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,cr,sm,ub=2e9,a[2][1069],as[2][1069],fq[2][1069],dsu[1069],cc[1069],ls[1069];
pair<long long,long long> vl[2][1069][1069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void ad(long long y,long long x,long long p,long long w)
{
	if(abs(y-a[0][p])+abs(x-a[1][p])<=w)
	{
		sm+=cc[fd(p)]*(ls[fd(p)]<cr);
		ls[fd(p)]=cr;
	}
}

int main()
{
	long long i,j,ii,k,l,p,y,x,lh,rh,md,zz=-1;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[ii][i]);
			as[ii][i]=a[ii][i];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(as[ii]+1,as[ii]+n+1);
		for(i=1;i<=n;i++)
		{
			p=lower_bound(as[ii]+1,as[ii]+n+1,a[ii][i])-as[ii];
			fq[ii][p]++;
			vl[ii][p][fq[ii][p]]={a[!ii][i],i};
		}
		for(i=1;i<=n;i++)
		{
			sort(vl[ii][i]+1,vl[ii][i]+fq[ii][i]+1);
		}
	}
	for(lh=1,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
			cc[i]=1;
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=2;j<=fq[ii][i];j++)
				{
					k=vl[ii][i][j].sc;
					l=vl[ii][i][j-1].sc;
					if(vl[ii][i][j].fr-vl[ii][i][j-1].fr<=md)
					{
						cc[fd(k)]+=cc[fd(l)]*(fd(k)!=fd(l));
						dsu[fd(l)]=fd(k);
					}
				}
			}
		}
		bad=cc[fd(1)]!=n;
		if(bad)
		{
			for(ii=0;ii<2&&bad;ii++)
			{
				for(i=1;i<=n&&bad;i++)
				{
					for(j=2;j<=fq[ii][i];j++)
					{
						k=vl[ii][i][j].sc;
						l=vl[ii][i][j-1].sc;
						if((vl[ii][i][j].fr-vl[ii][i][j-1].fr+1)/2<=md&&fd(k)!=fd(l)&&cc[fd(k)]+cc[fd(l)]==n)
						{
							bad=0;
							break;
						}
					}
				}
			}
		}
		if(bad)
		{
			for(i=1;i<=n;i++)
			{
				ls[i]=0;
			}
			for(i=1;i<=n&&bad;i++)
			{
				if(i-1&&as[0][i]==as[0][i-1])
				{
					continue;
				}
				y=as[0][i];
				for(j=1;j<=n;j++)
				{
					if(j-1&&as[1][j]==as[1][j-1])
					{
						continue;
					}
					cr=(i-1)*n+j;
					x=as[1][j];
					sm=0;
					for(ii=0;ii<2;ii++)
					{
						p=lower_bound(vl[ii][i]+1,vl[ii][i]+fq[ii][i]+1,mp(as[!ii][j],0ll))-vl[ii][i];
						if(p<=fq[ii][i])
						{
							ad(y,x,vl[ii][i][p].sc,md);
						}
						if(p-1)
						{
							ad(y,x,vl[ii][i][p-1].sc,md);
						}
						swap(i,j);
					}
					if(sm==n)
					{
						bad=0;
						break;
					}
				}
			}
		}
		if(!bad)
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