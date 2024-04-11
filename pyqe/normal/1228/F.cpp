#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long dn,n,nr[200069],pr[200069],rt[2],ht[200069],ex,sq[3],zs=0;
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,long long> mxe;

void dia(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	mxe=max(mxe,{nr[x],x});
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			nr[l]=nr[x]+1;
			pr[l]=x;
			dia(l);
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> cd;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(ex==-1)
			{
				return;
			}
			cd.push_back(ht[l]);
		}
	}
	sz=cd.size();
	if(!sz)
	{
		for(;sz<2;sz++)
		{
			cd.push_back(0);
		}
	}
	sort(cd.begin(),cd.end());
	if(sz==2&&cd[0]==cd[1]);
	else if((sz==1&&cd[0]==1)||(sz==3&&cd[0]==cd[1]&&cd[1]+1==cd[2]))
	{
		if(!ex)
		{
			ex=x;
		}
		else
		{
			ex=-1;
		}
	}
	else
	{
		ex=-1;
	}
	ht[x]=cd[sz-1]+1;
}

int main()
{
	long long i,ii,fh,k,l,p,mx,e;
	
	scanf("%lld",&dn);
	n=(1<<dn)-2;
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	e=1;
	for(ii=0;ii<2;ii++)
	{
		vtd.reset();
		mxe={-1e18,-1};
		nr[e]=0;
		dia(e);
		mx=mxe.fr;
		e=mxe.sc;
	}
	for(p=e;1;p=pr[p])
	{
		for(ii=0;ii<2;ii++)
		{
			if(nr[p]==(mx+ii)/2)
			{
				rt[ii]=p;
			}
		}
		if(!nr[p])
		{
			break;
		}
	}
	for(ii=0;ii<=mx%2;ii++)
	{
		vtd.reset();
		ex=0;
		dfs(rt[ii]);
		if(ex>0)
		{
			zs++;
			sq[zs]=ex;
		}
	}
	sort(sq+1,sq+zs+1);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}