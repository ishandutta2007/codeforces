#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,cr,ma=100,a[3069],da[3069],ls[169],wg[78069],z=0,inf=1e18;
vector<pair<long long,long long>> al[3069];
bitset<3069> vtd;
bool r0;

void ae(long long x,long long y,long long w)
{
	wg[m]=w;
	al[x].push_back({y,m});
	al[y].push_back({x,m+1});
	m+=2;
}

void dfs(long long x,long long mn)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	if(x==n+2)
	{
		z-=mn;
		cr=mn;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l]&&wg[p])
		{
			dfs(l,min(mn,wg[p]));
			if(r0)
			{
				wg[p]-=cr;
				wg[p^1]+=cr;
				return;
			}
		}
	}
}

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",da+i);
		if(da[i]>=0)
		{
			z+=da[i];
			ae(n+1,i,da[i]);
		}
		else
		{
			ae(i,n+2,-da[i]);
		}
		for(j=1;j<=ma;j++)
		{
			if(a[i]%j==0&&ls[j])
			{
				ae(i,ls[j],inf);
			}
		}
		ls[a[i]]=i;
	}
	for(r0=1;r0;)
	{
		vtd.reset();
		r0=0;
		dfs(n+1,inf);
	}
	printf("%lld\n",z);
}