#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,ma=4e9,wg[2069],dp[2069][2069],a[2069],sk[2069],dv=1e9+7,inf=1e18;
pair<long long,long long> ed[2069];
vector<pair<long long,long long>> al[2069];
pair<pair<long long,long long>,long long> as[2069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2>=x2*y;
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(a[y2]-a[x],wg[x]-wg[y2],a[y]-a[x],wg[x]-wg[y]);
}

long long tri(long long x)
{
	return x*(x+1)/2%dv;
}

int main()
{
	long long i,j,r,k,l,w,sz,mx,p,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,wg+i);
		ed[i]={k,l};
		al[k].push_back({l,wg[i]});
		al[l].push_back({k,wg[i]});
	}
	for(i=2;i<=n;i++)
	{
		dp[0][i]=-inf;
	}
	for(i=1;i<=m;i++)
	{
		a[i]=-inf;
	}
	for(i=1;i<=m;i++)
	{
		mx=-inf;
		for(j=1;j<=n;j++)
		{
			dp[i][j]=-inf;
			sz=al[j].size();
			for(r=0;r<sz;r++)
			{
				l=al[j][r].fr;
				w=al[j][r].sc;
				dp[i][j]=max(dp[i][j],dp[i-1][l]+w);
			}
			mx=max(mx,dp[i][j]);
		}
		z=(z+mx)%dv;
		for(j=1;j<=m;j++)
		{
			k=ed[j].fr;
			l=ed[j].sc;
			w=max(dp[i-1][k],dp[i-1][l]);
			if(w>=0)
			{
				a[j]=max(a[j],w-wg[j]*(i-1));
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		as[i]={{wg[i],-a[i]},i};
	}
	sort(as+1,as+m+1);
	for(i=1;i<=m;i++)
	{
		p=as[i].sc;
		if(i==1||as[i].fr.fr!=as[i-1].fr.fr)
		{
			for(;nn>=2&&chk(p,sk[nn],sk[nn-1]);nn--);
			nn++;
			sk[nn]=p;
		}
	}
	l=m;
	for(i=1;i<=nn;i++)
	{
		if(i<nn)
		{
			w=wg[sk[i+1]]-wg[sk[i]];
			k=(a[sk[i]]-a[sk[i+1]]-1+w*ma)/w-ma;
		}
		else
		{
			k=inf;
		}
		k=min(max(k,l),d);
		z=(z+(a[sk[i]]%dv+dv)*(k-l)+wg[sk[i]]*(tri(k)+dv-tri(l)))%dv;
		l=k;
	}
	printf("%lld\n",z);
}