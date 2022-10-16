#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn,r0=0,vl[2][100069],fq[2],pst[100069],tmp[100069],sq[100069],zs=0;
pair<long long,long long> ed[200069];
vector<long long> al[100069];
bitset<100069> vtd,vtd2,ds;
bool bad=0;

void dfs(long long x,long long ls)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	fq[ds[x]]++;
	vl[ds[x]][fq[ds[x]]]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==ls)
		{
			continue;
		}
		if(!vtd[l])
		{
			ds[l]=!ds[x];
			dfs(l,x);
		}
		else if(vtd2[l])
		{
			r0=l;
		}
		if(r0)
		{
			if(!bad)
			{
				zs++;
				sq[zs]=x;
			}
			if(x==r0)
			{
				bad=1;
			}
			return;
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,ii,k,l,df;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1,0);
	if(!r0)
	{
		for(ii=0;ii<2;ii++)
		{
			if(fq[ii]>=(d+1)/2)
			{
				printf("1\n");
				for(i=1;i<=(d+1)/2;i++)
				{
					printf("%lld%c",vl[ii][i]," \n"[i==(d+1)/2]);
				}
				return 0;
			}
		}
	}
	for(;1;)
	{
		for(i=1;i<=n;i++)
		{
			pst[i]=0;
		}
		for(i=1;i<=zs;i++)
		{
			pst[sq[i]]=i;
		}
		for(i=1;i<=m;i++)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			df=abs(pst[k]-pst[l]);
			if(pst[k]&&pst[l]&&df!=1&&df!=zs-1)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			break;
		}
		if(pst[k]>pst[l])
		{
			swap(k,l);
		}
		k=pst[k];
		l=pst[l];
		if(l-k>k+zs-l)
		{
			swap(k,l);
		}
		nn=0;
		for(i=k;i!=l%zs+1;i=i%zs+1)
		{
			nn++;
			tmp[nn]=sq[i];
		}
		for(i=1;i<=nn;i++)
		{
			sq[i]=tmp[i];
		}
		zs=nn;
	}
	if(zs>d)
	{
		printf("1\n");
		for(i=1;i<=d;i+=2)
		{
			printf("%lld%c",sq[i]," \n"[i>=d-1]);
		}
	}
	else
	{
		printf("2\n%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}