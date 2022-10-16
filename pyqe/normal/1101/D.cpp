#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ma=2e5,a[200069],ls[200069];
vector<long long> fz[200069],vl[200069];
pair<long long,long long> ed[200069];
vector<long long> al[200069];
bitset<200069> vtd[2];

pair<long long,long long> dfs(long long xx,long long x)
{
	long long i,sz=al[x].size(),l;
	pair<long long,long long> mx={1,x},tmp;
	
	vtd[xx][x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[xx][l])
		{
			tmp=dfs(xx,l);
			tmp.fr++;
			mx=max(mx,tmp);
		}
	}
	return mx;
}

int main()
{
	long long i,j,ii,iii,k,l,w,sz,pz,z=0;
	
	for(i=2;i<=ma;i++)
	{
		sz=fz[i].size();
		if(!sz)
		{
			for(j=i;j<=ma;j+=i)
			{
				fz[j].push_back(i);
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z|=a[i]>1;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		w=__gcd(a[k],a[l]);
		sz=fz[w].size();
		for(j=0;j<sz;j++)
		{
			l=fz[w][j];
			vl[l].push_back(i);
		}
	}
	for(i=1;i<=ma;i++)
	{
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			pz=vl[i][j];
			k=ed[pz].fr;
			l=ed[pz].sc;
			for(ii=0;ii<2;ii++)
			{
				if(ls[k]<i)
				{
					ls[k]=i;
					al[k].clear();
					for(iii=0;iii<2;iii++)
					{
						vtd[iii][k]=0;
					}
				}
				al[k].push_back(l);
				swap(k,l);
			}
		}
		for(j=0;j<sz;j++)
		{
			pz=vl[i][j];
			k=ed[pz].fr;
			if(!vtd[0][k])
			{
				z=max(z,dfs(1,dfs(0,k).sc).fr);
			}
		}
	}
	printf("%lld\n",z);
}