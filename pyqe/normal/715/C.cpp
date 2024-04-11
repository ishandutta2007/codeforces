#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nv=0,cr,ctd,nn,pc[2][100069],vi[100069],sbt[100069],ca[2][100069],z=0,pwk,dv,inf=1e18;
vector<pair<long long,long long>> al[100069];
map<long long,long long> fq[2];

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

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

void bd2(long long x)
{
	long long i,sz=al[x].size(),l,mx=sbt[cr]-sbt[x];
	
	vi[x]=nv;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(vi[l]<nv)
		{
			bd2(l);
			mx=max(mx,sbt[l]);
		}
	}
	if(mx*2<=sbt[cr])
	{
		ctd=x;
	}
}

void trv(long long x,long long cdh,long long ww,long long ww2)
{
	long long i,ii,sz=al[x].size(),l,w;
	
	vi[x]=nv;
	nn++;
	for(ii=0;ii<2;ii++)
	{
		z+=fq[!ii][(dv-ww)%dv];
		ca[ii][nn]=ww;
		swap(ww,ww2);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(vi[l]<nv)
		{
			trv(l,cdh+1,(ww+w*pc[0][cdh])%dv,(ww2+w*pc[1][cdh+1])%dv);
		}
	}
}

void cdc(long long x)
{
	long long i,j,ii,sz,l,w;
	
	cr=x;
	nv++;
	bd(x);
	nv++;
	bd2(x);
	x=ctd;
	vi[x]=inf;
	for(ii=0;ii<2;ii++)
	{
		fq[ii].clear();
		fq[ii][0]++;
	}
	sz=al[x].size();
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(vi[l]!=inf)
		{
			nn=0;
			nv++;
			trv(l,1,w,w*pc[1][1]%dv);
			for(ii=0;ii<2;ii++)
			{
				for(j=1;j<=nn;j++)
				{
					fq[ii][ca[ii][j]]++;
				}
			}
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(vi[l]!=inf)
		{
			cdc(l);
		}
	}
}

int main()
{
	long long i,ii,k,l,w;
	
	scanf("%lld%lld",&n,&dv);
	k=dv;
	w=dv;
	for(i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			w=w/i*(i-1);
			for(;k%i==0;k/=i);
		}
	}
	if(k-1)
	{
		w=w/k*(k-1);
	}
	for(ii=0;ii<2;ii++)
	{
		pc[ii][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		pc[0][i]=pc[0][i-1]*10%dv;
		pc[1][i]=pw(pc[0][i],w-1);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		k++;
		l++;
		w%=dv;
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	cdc(1);
	printf("%lld\n",z);
}