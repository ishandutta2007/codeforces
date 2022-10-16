#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[3069],dsu[3069],od[3069],sq[6069],zs=0;
pair<long long,long long> ed[3069];
vector<pair<long long,long long>> al[3069];
bitset<3069> spc,vtd;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void eup(long long x)
{
	long long sz=al[x].size(),l,p;
	
	for(;od[x]<sz;)
	{
		l=al[x][od[x]].fr;
		p=al[x][od[x]].sc;
		od[x]++;
		if(!vtd[p])
		{
			vtd[p]=1;
			eup(l);
		}
	}
	zs++;
	sq[zs]=x;
}

int main()
{
	long long i,j,r,ii,k,l,sz,p,c,st;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back({l,i});
			dg[k]++;
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=-1;j<sz;j++)
		{
			for(r=0;r<sz;r++)
			{
				l=al[i][r].fr;
				p=al[i][r].sc;
				if(r!=j&&dg[l]%2)
				{
					spc[p]=1;
					dg[i]--;
					dg[l]--;
				}
			}
			c=0;
			for(r=1;r<=n;r++)
			{
				c+=r!=i&&dg[r]%2;
				dsu[r]=r;
			}
			if(c<=1)
			{
				for(r=1;r<=m;r++)
				{
					k=ed[r].fr;
					l=ed[r].sc;
					if(!spc[r])
					{
						dsu[fd(l)]=fd(k);
					}
				}
				for(r=1;r<=m;r++)
				{
					if(fd(r)!=fd(i)&&dg[r])
					{
						break;
					}
				}
				if(r>m)
				{
					break;
				}
			}
			for(r=0;r<sz;r++)
			{
				l=al[i][r].fr;
				p=al[i][r].sc;
				if(spc[p])
				{
					spc[p]=0;
					dg[i]++;
					dg[l]++;
				}
			}
		}
		if(j<sz)
		{
			break;
		}
	}
	if(i>n)
	{
		printf("0\n");
		return 0;
	}
	st=i;
	for(i=1;i<=n;i++)
	{
		al[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(!spc[i])
		{
			al[k].push_back({l,i});
			al[l].push_back({k,i});
		}
	}
	eup(st);
	zs++;
	sq[zs]=-1;
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(spc[i])
		{
			if(k!=st)
			{
				swap(k,l);
			}
			zs++;
			sq[zs]=l;
			zs++;
			sq[zs]=k;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}