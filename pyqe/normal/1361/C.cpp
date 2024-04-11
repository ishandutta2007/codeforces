#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,a[500069][2],dsu[1ll<<20],ce[1ll<<20],od[1ll<<20],sq[1000069],zs=0;
bitset<1ll<<20> dg;
vector<pair<int,int>> al[1ll<<20];
bitset<500069> vtd;

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(int x,int ls)
{
	int i,sz=al[x].size(),l,p;
	
	for(;od[x]<sz;)
	{
		l=al[x][od[x]].fr;
		p=al[x][od[x]].sc;
		od[x]++;
		if(!vtd[(p+1)/2])
		{
			vtd[(p+1)/2]=1;
			dfs(l,p);
		}
	}
	if(ls)
	{
		zs+=2;
		sq[zs-1]=(ls-1)/2*2+1+ls%2;
		sq[zs]=ls;
	}
}

int main()
{
	int i,ii,k,l,lh,rh,md,zz;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%d",&a[i][ii]);
		}
	}
	for(lh=0,rh=20;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=0;i<1ll<<md;i++)
		{
			dg[i]=0;
			dsu[i]=i;
			ce[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				k=a[i][ii]%(1ll<<md);
				dg[k]=!dg[k];
				swap(k,l);
			}
			if(fd(k)!=fd(l))
			{
				ce[fd(k)]+=ce[fd(l)];
				dsu[fd(l)]=fd(k);
			}
			ce[fd(k)]++;
		}
		for(i=0;i<1ll<<md;i++)
		{
			if(dg[i]||(ce[fd(i)]&&ce[fd(i)]<n))
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			k=a[i][ii]%(1ll<<zz);
			swap(k,l);
		}
		al[k].push_back({l,i*2-1});
		al[l].push_back({k,i*2});
	}
	for(i=0;i<1ll<<zz;i++)
	{
		if(!al[i].empty())
		{
			dfs(i,0);
			break;
		}
	}
	printf("%d\n",zz);
	for(i=1;i<=zs;i++)
	{
		printf("%d%c",sq[i]," \n"[i==zs]);
	}
}