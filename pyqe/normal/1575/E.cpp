#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=1e9+7,iv=5e8+4,inf=1e18;
long long n,d,nv=0,ub,a[200069],vi[200069],sbt[200069],fq[2][3][200069],ps[2][3][200069],z=0;
vector<pair<long long,long long>> al[200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vi[x]=nv;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(vi[l]<nv)
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

long long fctd(long long x,long long cw)
{
	long long i,sz=al[x].size(),k=0,l,mx=cw-sbt[x];
	
	vi[x]=nv;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(vi[l]<nv)
		{
			k=max(k,fctd(l,cw));
			mx=max(mx,sbt[l]);
		}
	}
	if(mx*2<=cw)
	{
		k=x;
	}
	return k;
}

void trv(long long x,long long e,long long cw,long long b4,long long cw2)
{
	long long i,ii,jj,sz=al[x].size(),l,w;
	
	vi[x]=nv;
	for(;ub<cw;)
	{
		ub++;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<3;jj++)
			{
				fq[ii][jj][ub]=0;
			}
		}
	}
	fq[0][e][cw]++;
	fq[1][e][cw]=(fq[1][e][cw]+cw2)%dv;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(vi[l]<nv)
		{
			trv(l,e!=2?e:w,cw+(b4!=2&&w!=b4),w,(cw2+a[l])%dv);
		}
	}
}

void trv2(long long x,long long e,long long cw,long long b4,long long cw2,long long u)
{
	long long i,ii,sz=al[x].size(),l,w,p;
	
	vi[x]=nv;
	for(ii=0;ii<3;ii++)
	{
		p=min(d-(cw+(e!=2&&ii!=2&&ii!=e)),ub);
		if(p>=0)
		{
			z=(z+(cw2*ps[0][ii][p]%dv+ps[1][ii][p])*u)%dv;
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(vi[l]<nv)
		{
			trv2(l,e!=2?e:w,cw+(b4!=2&&w!=b4),w,(cw2+a[l])%dv,u);
		}
	}
}

inline void slv(long long x,long long e,long long cw2,long long cw22,long long u)
{
	long long i,ii,jj;
	
	ub=-1;
	nv++;
	trv(x,e,0,e,cw2);
	for(ii=0;ii<2;ii++)
	{
		for(jj=0;jj<3;jj++)
		{
			for(i=0;i<=ub;i++)
			{
				ps[ii][jj][i]=fq[ii][jj][i];
				if(i)
				{
					ps[ii][jj][i]=(ps[ii][jj][i]+ps[ii][jj][i-1])%dv;
				}
			}
		}
	}
	nv++;
	trv2(x,e,0,e,cw22,u);
}

void cdc(long long x)
{
	long long i,k,l,w,sz;
	
	nv++;
	bd(x);
	nv++;
	k=fctd(x,sbt[x]);
	slv(k,2,a[k],0,1);
	vi[k]=inf;
	sz=al[k].size();
	for(i=0;i<sz;i++)
	{
		l=al[k][i].fr;
		w=al[k][i].sc;
		if(vi[l]!=inf)
		{
			slv(l,w,(a[k]+a[l])%dv,a[l],dv-1);
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[k][i].fr;
		if(vi[l]!=inf)
		{
			cdc(l);
		}
	}
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z=(z+a[i])%dv;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	cdc(1);
	z=z*iv%dv;
	printf("%lld\n",z);
}