#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,sbt[100069],dp[100069],dh[100069],pst[100069],lg2[200069];
vector<long long> al[100069],dpl[100069],psl[100069];
bitset<100069> vtd;
pair<long long,long long> sp[18][200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	
	vtd[x]=1;
	sbt[x]=1;
	nn++;
	pst[x]=nn;
	sp[0][nn]={dh[x],x};
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bd(l);
			sbt[x]+=sbt[l];
			dp[x]+=dp[l]+sbt[l];
			v.push_back(l);
			nn++;
			sp[0][nn]={dh[x],x};
			psl[x].push_back(pst[l]);
		}
	}
	al[x]=v;
}

void bd2(long long x,long long w)
{
	long long i,sz=al[x].size(),l,ww;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		ww=w+sbt[1]-sbt[x]+dp[x]-(dp[l]+sbt[l]);
		dpl[x].push_back(ww);
		bd2(l,ww);
	}
}

void spbd()
{
	long long i,j,k;
	
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=1;j<=nn-(1ll<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

long long qr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]).sc;
}

long long lca(long long x,long long y)
{
	if(pst[x]>pst[y])
	{
		swap(x,y);
	}
	return qr(pst[x],pst[y]);
}

int main()
{
	long long t,rr,i,ii,k,l,p,w[2],ww[2],e,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	bd2(1,0);
	spbd();
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		p=lca(k,l);
		if(p!=k&&p!=l)
		{
			for(ii=0;ii<2;ii++)
			{
				w[ii]=sbt[k];
				ww[ii]=dp[k];
				swap(k,l);
			}
		}
		else
		{
			if(k!=p)
			{
				swap(k,l);
			}
			e=upper_bound(psl[k].begin(),psl[k].end(),pst[l])-psl[k].begin()-1;
			w[0]=sbt[1]-sbt[al[k][e]];
			ww[0]=dpl[k][e];
			w[1]=sbt[l];
			ww[1]=dp[l];
		}
		z=ww[0]*w[1]+ww[1]*w[0]+(dh[k]+dh[l]-dh[p]*2+1)*w[0]*w[1];
		printf("%.8lf\n",(double)z/(w[0]*w[1]));
	}
}