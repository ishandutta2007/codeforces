#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,ne=0,nn,wg[320069],nr[80069],ca[40069],z=0;
bitset<269> a[269];
bitset<80069> spc,vtd;
vector<pair<long long,long long>> al[80069],pr[80069];
queue<long long> q;
bool r0;

void ae(long long x,long long y)
{
	al[x].push_back({y,ne});
	al[y].push_back({x,ne+1});
	wg[ne]=1;
	ne+=2;
}

void dfs(long long x)
{
	long long i,sz=pr[x].size(),l,p;
	
	vtd[x]=1;
	if(x%2==0&&!spc[x])
	{
		z++;
		spc[x]=1;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=pr[x][i].fr;
		p=pr[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				spc[x]=1;
				wg[p]--;
				wg[p^1]++;
				return;
			}
		}
	}
}

int main()
{
	long long i,j,ii,jj,k,l,p,sz,ub;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='#';
			z+=a[i][j];
			for(ii=0;ii<2;ii++)
			{
				k=(i*m+j)*2+ii;
				spc[k]=a[i][j]&&i-ii>=0&&j-!ii>=0&&a[i-ii][j-!ii];
				z-=spc[k];
			}
			if(i&&j)
			{
				for(ii=0;ii<2;ii++)
				{
					for(jj=0;jj<2;jj++)
					{
						k=((i-ii)*m+j)*2;
						l=(i*m+j-jj)*2+1;
						if(spc[k]&&spc[l])
						{
							ae(k,l);
						}
					}
				}
			}
		}
	}
	spc.reset();
	for(nn=1;nn;)
	{
		for(i=0;i<n*m*2;i++)
		{
			nr[i]=inf;
			if(i%2==0&&!spc[i])
			{
				q.push(i);
				nr[i]=0;
			}
			pr[i].clear();
		}
		ub=inf;
		vtd.reset();
		nn=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			if(nr[k]>=ub)
			{
				continue;
			}
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i].fr;
				p=al[k][i].sc;
				if(wg[p])
				{
					if(nr[k]+1<nr[l])
					{
						q.push(l);
						nr[l]=nr[k]+1;
						if(!spc[l])
						{
							ub=min(ub,nr[l]);
							if(!vtd[l])
							{
								vtd[l]=1;
								nn++;
								ca[nn]=l;
							}
						}
					}
					if(nr[k]+1==nr[l])
					{
						pr[l].push_back({k,p});
					}
				}
			}
		}
		vtd.reset();
		for(i=1;i<=nn;i++)
		{
			r0=0;
			dfs(ca[i]);
		}
	}
	printf("%lld\n",z);
}