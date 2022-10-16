#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,wg[400069],ls[400069],dsu[400069],dh[400069],dp[400069][2];
bitset<400069> a;
vector<long long> al[400069],al2[400069];
bitset<400069> vtd,vtd2;
pair<long long,long long> rg[400069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void scc(long long x)
{
	long long i,sz=al[x].size(),l;
	
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
			dp[fd(l)][0]=min(dp[fd(l)][0],dp[fd(x)][0]);
			dp[fd(l)][1]=max(dp[fd(l)][1],dp[fd(x)][1]);
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

void dfs(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		dp[x][0]=min(dp[x][0],dp[l][0]);
		dp[x][1]=max(dp[x][1],dp[l][1]);
	}
}

int main()
{
	long long i,j,ii,k,l,sz,p,c,mx,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			scanf(" %c",&ch);
			a[p]=ch=='#';
			dsu[p]=p;
			for(ii=0;ii<2;ii++)
			{
				dp[p][ii]=j;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",wg+i);
		ls[i]=-1;
	}
	for(i=n-1;i+1;i--)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			if(a[p])
			{
				if(ls[j]+1)
				{
					al[p].push_back(ls[j]);
				}
				if(j&&ls[j-1]+1)
				{
					al[p].push_back(ls[j-1]);
				}
				if(i&&a[p-m])
				{
					al[p].push_back(p-m);
				}
				ls[j]=p;
			}
		}
		for(j=0;j<m-1;j++)
		{
			p=i*m+j;
			if(a[p])
			{
				if(ls[j+1]+1)
				{
					al[p].push_back(ls[j+1]);
				}
			}
		}
	}
	for(i=0;i<n*m;i++)
	{
		if(a[i]&&!vtd[i])
		{
			scc(i);
		}
	}
	for(i=0;i<n*m;i++)
	{
		if(a[i])
		{
			sz=al[i].size();
			for(j=0;j<sz;j++)
			{
				l=al[i][j];
				if(fd(i)!=fd(l))
				{
					al2[fd(l)].push_back(fd(i));
				}
			}
		}
	}
	vtd.reset();
	for(i=0;i<m;i++)
	{
		if(wg[i])
		{
			c=0;
			for(j=n-1;1;j--)
			{
				p=j*m+i;
				c+=a[p];
				if(c==wg[i])
				{
					break;
				}
			}
			if(!vtd[fd(p)])
			{
				dfs(fd(p));
			}
			nn++;
			rg[nn]={dp[fd(p)][1],dp[fd(p)][0]};
		}
	}
	sort(rg+1,rg+nn+1);
	mx=-1;
	for(i=1;i<=nn;i++)
	{
		l=rg[i].fr;
		k=rg[i].sc;
		if(k>mx)
		{
			z++;
			mx=l;
		}
	}
	printf("%lld\n",z);
}