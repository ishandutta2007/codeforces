#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,nv=0,cr,dsu[200069],cc[200069],fq[200069],ca[200069],vi[200069];
pair<long long,long long> ed[400069],as[400069];
vector<long long> al[200069];
vector<pair<long long,bool>> al2[200069];
bitset<400069> spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

bool dfs(long long x,bool bad)
{
	long long i,sz=al2[x].size(),l;
	bool w,z=x==cr&&bad;
	
	vi[x]=nv;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i].fr;
		w=al2[x][i].sc;
		if(vi[l]<nv)
		{
			z|=dfs(l,bad||w);
		}
	}
	return z;
}

int main()
{
	long long i,j,k,l,w,sz,p,xr=0,z=0;
	bool bad=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(k>l)
		{
			swap(k,l);
		}
		ed[i]={k,l};
		al[l].push_back(k);
		as[i]={w,i};
		xr^=w;
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			fq[fd(l)]--;
		}
		dsu[i]=i;
		cc[i]=1;
		sz=nn;
		nn=0;
		for(j=1;j<=sz;j++)
		{
			if(fq[ca[j]])
			{
				cc[i]+=cc[ca[j]];
				dsu[ca[j]]=i;
				m++;
				ed[m]={ca[j],i};
				as[m]={0,m};
				bad&=fq[ca[j]]==1;
			}
			else
			{
				nn++;
				ca[nn]=ca[j];
				fq[ca[j]]=cc[ca[j]];
			}
		}
		nn++;
		ca[nn]=i;
		fq[i]=cc[i];
	}
	sort(as+1,as+m+1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		w=as[i].fr;
		p=as[i].sc;
		k=ed[p].fr;
		l=ed[p].sc;
		if(fd(k)!=fd(l))
		{
			z+=w;
			dsu[fd(l)]=fd(k);
			al2[k].push_back({l,!w});
			al2[l].push_back({k,!w});
			spc[i]=1;
		}
	}
	if(bad)
	{
		for(i=1;i<=m;i++)
		{
			if(!spc[i])
			{
				w=as[i].fr;
				p=as[i].sc;
				k=ed[p].fr;
				l=ed[p].sc;
				cr=l;
				nv++;
				if(dfs(k,0))
				{
					xr=min(xr,w);
				}
			}
		}
		z+=xr;
	}
	printf("%lld\n",z);
}