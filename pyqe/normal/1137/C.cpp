#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,d,vp=0,dsu[100069],dh[100069],vi[100069],ga[100069],fq[100069][69],dp[100069][69],z=0,inf=1e9;
pair<int,int> ed[100069];
vector<int> al[100069];
bitset<100069> vtd,vtd2;
bool r0;
vector<pair<int,int>> al2[100069];
bitset<69> a;

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void scc(int x)
{
	int i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			scc(l);
		}
		if(vtd2[fd(l)]&&dh[fd(l)]<dh[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

void clr(int mo,int x)
{
	int i,sz=al[x].size(),l;
	
	vi[x]=vp;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(fd(l)!=fd(x))
		{
			continue;
		}
		if(vi[l]<vp)
		{
			dh[l]=(dh[x]+1)%mo;
			clr(mo,l);
			if(r0)
			{
				return;
			}
		}
		else if(dh[l]!=(dh[x]+1)%mo)
		{
			r0=1;
			return;
		}
	}
}

void dfs(int x)
{
	int i,j,sz=al2[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i].fr;
		w=al2[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
		}
		for(j=0;j<d;j++)
		{
			dp[x][(j+w)%ga[x]]=max(dp[x][(j+w)%ga[x]],dp[l][j]);
		}
	}
	for(i=0;i<ga[x];i++)
	{
		dp[x][i]+=fq[x][i];
		z=max(z,dp[x][i]);
	}
	for(i=ga[x];i<d;i++)
	{
		dp[x][i]=dp[x][i-ga[x]];
	}
}

int main()
{
	int i,j,k,l;
	char ch;
	
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			scc(i);
		}
		if(fd(i)==i)
		{
			for(j=1;j<=d;j++)
			{
				if(d%j==0)
				{
					r0=0;
					vp++;
					dh[i]=0;
					clr(j,i);
					if(!r0)
					{
						ga[i]=j;
					}
				}
			}
			vp++;
			dh[i]=0;
			clr(ga[i],i);
		}
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(fd(k)!=fd(l))
		{
			al2[fd(l)].push_back({fd(k),(dh[k]+d-dh[l]+1)%d});
		}
	}
	for(i=1;i<=n;i++)
	{
		a.reset();
		for(j=0;j<d;j++)
		{
			scanf(" %c",&ch);
			if(ch-'0')
			{
				a[(j+d-dh[i])%ga[fd(i)]]=1;
			}
			dp[i][j]=-inf;
		}
		for(j=0;j<ga[fd(i)];j++)
		{
			fq[fd(i)][j]+=a[j];
		}
	}
	dp[fd(1)][(d-dh[1])%ga[fd(1)]]=0;
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i&&!vtd[i])
		{
			dfs(i);
		}
	}
	printf("%d\n",z);
}