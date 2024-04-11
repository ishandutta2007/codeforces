#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,dh[900069],pr[900069][20],pst[900069],dp[900069][2],fq[900069],z=0;
vector<long long> al[900069];
bitset<900069> vtd;
vector<pair<long long,long long>> vl[900069];

void bd(long long x)
{
	long long i,j,sz=al[x].size(),l;
	vector<long long> v;
	
	vtd[x]=1;
	nn++;
	pst[x]=nn;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l][0]=x;
			for(j=1;j<20;j++)
			{
				pr[l][j]=pr[pr[l][j-1]][j-1];
			}
			bd(l);
			v.push_back(l);
		}
	}
	al[x]=v;
}

long long lca(long long x,long long y)
{
	long long i,ii;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=19;i+1;i--)
		{
			if(dh[pr[x][i]]>=dh[y])
			{
				x=pr[x][i];
			}
		}
		swap(x,y);
	}
	for(i=19;i+1;i--)
	{
		if(pr[x][i]!=pr[y][i])
		{
			x=pr[x][i];
			y=pr[y][i];
		}
	}
	if(x!=y)
	{
		x=pr[x][0];
	}
	return x;
}

void bd2(long long x)
{
	long long i,ii,sz=al[x].size(),k,l,c;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		bd2(l);
		for(ii=0;ii<2;ii++)
		{
			dp[x][ii]+=dp[l][ii];
		}
	}
	sort(vl[x].begin(),vl[x].end());
	sz=vl[x].size();
	z+=sz*(sz-1)/2-fq[x]*(fq[x]-1)/2;
	for(i=0;i<sz;i++)
	{
		k=vl[x][i].fr;
		l=vl[x][i].sc;
		z+=dp[x][0]-dp[k][1]-dp[l][1];
		c=(c+1)*(i&&vl[x][i]==vl[x][i-1]);
		z+=c;
	}
}

int main()
{
	long long i,ii,k,l,sz,p,la,lh,rh,md,zz,kk,ll;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			p=n+i*2-!ii;
			al[k].push_back(p);
			al[p].push_back(k);
			swap(k,l);
		}
	}
	bd(1);
	for(i=1;i<=m;i++)
	{
		k=n+i*2-1;
		l=n+i*2;
		la=lca(k,l);
		for(ii=0;ii<2;ii++)
		{
			dp[k][ii]++;
			dp[l][ii]++;
		}
		dp[la][0]-=2;
		sz=al[la].size();
		for(ii=0;ii<2;ii++)
		{
			for(lh=0,rh=sz-1;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(pst[al[la][md]]<=pst[k])
				{
					zz=al[la][md];
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			dp[zz][1]--;
			kk=zz;
			fq[zz]++;
			swap(k,l);
			swap(kk,ll);
		}
		if(kk>ll)
		{
			swap(kk,ll);
		}
		vl[la].push_back({kk,ll});
	}
	bd2(1);
	printf("%lld\n",z);
}