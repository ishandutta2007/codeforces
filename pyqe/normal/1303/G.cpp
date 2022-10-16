#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nd=17,rr,cr,ctd,nn,nm,a[150069],ls[150069],sbt[150069],od[150069],inf=1e18;
vector<long long> al[150069];
array<long long,4> ca[150069];

long long f(long long x,long long w)
{
	return ca[x][1]*w+ca[x][3];
}

struct lichao
{
	long long l,r,mx;
	lichao *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii;
		
		l=lh;
		r=rh;
		mx=0;
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
	}
	void blc()
	{
		long long ii,md=(l+r)/2;
		
		for(ii=0;ii<2;ii++)
		{
			if(!p[ii])
			{
				p[ii]=new lichao;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ins(long long x)
	{
		long long ii,md=(l+r)/2;
		
		if(f(x,md)>f(mx,md))
		{
			swap(x,mx);
		}
		blc();
		for(ii=0;ii<2;ii++)
		{
			if(f(x,l)>f(mx,l))
			{
				p[ii]->ins(x);
			}
			swap(l,r);
		}
	}
	long long qr(long long x)
	{
		if(l>x||r<x)
		{
			return -inf;
		}
		else
		{
			long long ii,z=f(mx,x);
			
			for(ii=0;ii<2;ii++)
			{
				if(p[ii])
				{
					z=max(z,p[ii]->qr(x));
				}
			}
			return z;
		}
	}
}
lch;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	ls[x]=rr*3;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3)
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void bd2(long long x)
{
	long long i,sz=al[x].size(),l,mx=sbt[cr]-sbt[x];
	
	ls[x]=rr*3+1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3+1)
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

void trv(long long x,array<long long,4> w)
{
	long long i,sz=al[x].size(),l;
	
	ls[x]=rr*3+2;
	nn++;
	ca[nn]=w;
	od[nn]=nm;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3+2)
		{
			nm+=x==ctd;
			trv(l,{w[0]+1,w[1]+a[l],w[2]+w[1]+a[l],w[3]+a[l]*(w[0]+1)});
		}
	}
}

int main()
{
	long long i,j,r,ii,k,l,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ls[i]=-1;
	}
	for(rr=0;rr<nd;rr++)
	{
		for(i=1;i<=n;i++)
		{
			if(ls[i]<rr*3)
			{
				cr=i;
				bd(i);
				bd2(i);
				nn=0;
				nm=1;
				trv(ctd,{0,0,0,0});
				for(ii=0;ii<2;ii++)
				{
					lch.bd(1,n);
					for(r=0,j=1;j<=nn;j++)
					{
						for(;od[r+1]<od[j];)
						{
							r++;
							lch.ins(r);
						}
						z=max(z,ca[j][2]+a[ctd]*(ca[j][0]+1)+lch.qr(ca[j][0]+1));
					}
					for(j=1;j<nn+1-j;j++)
					{
						swap(ca[j],ca[nn+1-j]);
						swap(od[j],od[nn+1-j]);
					}
					for(j=1;j<=nn;j++)
					{
						od[j]=nm+1-od[j];
					}
				}
				ls[ctd]=nd*3;
			}
		}
	}
	printf("%lld\n",z);
}