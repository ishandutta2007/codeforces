#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn[2],dsu[100069],sq[100069],zs=0,ub=1e12,inf=1e18;
pair<long long,long long> ed[100069];
pair<long long,long long> as[2][100069];
bitset<100069> spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,r,ii,k,l,w,pz,p[2],e,lh,rh,md,zz=-inf,c,dd,cc,mn=inf,ls;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		e=min(k,l)==1;
		nn[e]++;
		as[e][nn[e]]={w,i};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(as[ii]+1,as[ii]+nn[ii]+1);
		as[ii][nn[ii]+1].fr=inf;
	}
	for(lh=-ub,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
		}
		for(ii=0;ii<2;ii++)
		{
			p[ii]=1;
		}
		c=0;
		cc=0;
		for(;p[0]<=nn[0]||p[1]<=nn[1];p[e]++)
		{
			e=as[1][p[1]].fr+md<=as[0][p[0]].fr;
			pz=as[e][p[e]].sc;
			k=ed[pz].fr;
			l=ed[pz].sc;
			c+=e*(fd(k)!=fd(l));
			cc+=fd(k)!=fd(l);
			dsu[fd(l)]=fd(k);
		}
		if(cc<n-1)
		{
			printf("-1\n");
			return 0;
		}
		if(c>=d)
		{
			zz=md;
			dd=c;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
		mn=min(mn,c);
	}
	if(zz==-inf||mn>d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	ls=0;
	for(j=1,i=1;i<=nn[1]+1;i++)
	{
		for(;j<=nn[0]&&as[0][j].fr<as[1][i].fr+zz;j++)
		{
			pz=as[0][j].sc;
			k=ed[pz].fr;
			l=ed[pz].sc;
			if(fd(k)!=fd(l))
			{
				dsu[fd(l)]=fd(k);
				zs++;
				sq[zs]=pz;
			}
		}
		if(i<=nn[1]&&as[1][i].fr!=as[1][i+1].fr)
		{
			for(r=ls+1;r<=i;r++)
			{
				pz=as[1][r].sc;
				k=ed[pz].fr;
				l=ed[pz].sc;
				spc[fd(k)]=1;
				spc[fd(l)]=1;
			}
			for(r=j;r<=nn[0]&&as[0][r].fr<=as[1][i].fr+zz;r++)
			{
				pz=as[0][r].sc;
				k=ed[pz].fr;
				l=ed[pz].sc;
				if(fd(k)!=fd(l)&&spc[fd(k)]&&spc[fd(l)]&&dd>d)
				{
					dsu[fd(l)]=fd(k);
					zs++;
					sq[zs]=pz;
					dd--;
				}
			}
			for(r=ls+1;r<=i;r++)
			{
				pz=as[1][r].sc;
				k=ed[pz].fr;
				l=ed[pz].sc;
				spc[fd(k)]=0;
				spc[fd(l)]=0;
				if(fd(k)!=fd(l))
				{
					dsu[fd(l)]=fd(k);
					zs++;
					sq[zs]=pz;
				}
			}for(;j<=nn[0]&&as[0][j].fr<=as[1][i].fr+zz;j++)
			{
				pz=as[0][j].sc;
				k=ed[pz].fr;
				l=ed[pz].sc;
				if(fd(k)!=fd(l))
				{
					dsu[fd(l)]=fd(k);
					zs++;
					sq[zs]=pz;
				}
			}
			ls=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}