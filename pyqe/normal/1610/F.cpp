#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nm,dsu[200069],lz[200069];
vector<pair<long long,pair<long long,bool>>> al[2][100069];
bitset<200069> vtd;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		long long k=dsu[x];
		
		dsu[x]=fd(dsu[x]);
		lz[x]^=lz[k];
	}
	return dsu[x];
}

inline void jo(long long x,long long y,long long w)
{
	fd(x);
	fd(y);
	w^=lz[x]^lz[y];
	x=fd(x);
	y=fd(y);
	dsu[y]=x;
	lz[y]=w;
}

int main()
{
	long long i,j,ii,k,l,w,sz,p,e,k2,l2,p2,e2,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[w-1][k].push_back({l,{i,0}});
		al[w-1][l].push_back({k,{i,1}});
		dsu[i]=i;
	}
	nm=m;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			sz=al[ii][i].size();
			for(k2=-1;1;)
			{
				for(k=k2+1;k<sz&&vtd[al[ii][i][k].sc.fr];k++);
				for(k2=k+1;k2<sz&&vtd[al[ii][i][k2].sc.fr];k2++);
				if(k2>=sz)
				{
					break;
				}
				l=al[ii][i][k].fr;
				p=al[ii][i][k].sc.fr;
				e=al[ii][i][k].sc.sc;
				l2=al[ii][i][k2].fr;
				p2=al[ii][i][k2].sc.fr;
				e2=al[ii][i][k2].sc.sc;
				vtd[p]=1;
				vtd[p2]=1;
				nm++;
				dsu[nm]=nm;
				jo(nm,p,!e);
				jo(nm,p2,e2);
				if(l!=l2)
				{
					al[ii][l].push_back({l2,{nm,0}});
					al[ii][l2].push_back({l,{nm,1}});
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		p=-1;
		p2=-1;
		for(ii=0;ii<2;ii++)
		{
			sz=al[ii][i].size();
			for(j=0;j<sz&&vtd[al[ii][i][j].sc.fr];j++);
			if(j<sz)
			{
				if(!ii)
				{
					z++;
					p=al[ii][i][j].sc.fr;
					e=al[ii][i][j].sc.sc;
				}
				else
				{
					p2=al[ii][i][j].sc.fr;
					e2=al[ii][i][j].sc.sc;
				}
			}
		}
		if(p!=-1&&p2!=-1)
		{
			jo(p,p2,!e^e2);
		}
	}
	printf("%lld\n",z);
	for(i=1;i<=m;i++)
	{
		fd(i);
		printf("%lld",lz[i]+1);
	}
	printf("\n");
}