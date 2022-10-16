#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=3;
long long n,ln,nn=0,tmp[mm+1][mm+1],mt[1<<3][mm+1][mm+1],m0[mm+1][mm+1],m1[mm+1][mm+1],mz[mm+1][mm+1],a1[mm+1],az[mm+1],fq[mm],dv=1e9+7;
pair<long long,long long> a[20069];

void cop(long long x[mm+1][mm+1],long long y[mm+1][mm+1])
{
	long long i,j;
	
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<=mm;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm+1][mm+1],long long y[mm+1][mm+1],long long z[mm+1][mm+1])
{
	long long i,j,r;
	
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<=mm;j++)
		{
			tmp[i][j]=0;
			for(r=1;r<=mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	cop(tmp,z);
}

void mpw(long long x)
{
	if(!x)
	{
		cop(m0,mz);
		return;
	}
	mpw(x/2);
	mul(mz,mz,mz);
	if(x%2)
	{
		mul(mz,m1,mz);
	}
}

int main()
{
	long long i,j,r,u,k,l,w,mk;
	
	for(i=1;i<=mm;i++)
	{
		m0[i][i]=1;
	}
	for(mk=0;mk<1<<mm;mk++)
	{
		for(i=1;i<=mm;i++)
		{
			if(mk>>i-1&1)
			{
				for(j=max(i-1,1ll);j<=min(i+1,mm);j++)
				{
					mt[mk][i][j]++;
				}
			}
		}
	}
	a1[2]=1;
	scanf("%lld%lld",&n,&ln);
	nn=n*2+1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&w,&k,&l);
		a[i*2-1]={k-1,w};
		a[i*2]={l,-w};
	}
	a[nn]={ln,1};
	sort(a+1,a+nn+1);
	l=1;
	mk=(1<<mm)-1;
	for(i=1;i<=nn;i++)
	{
		k=a[i].fr;
		w=a[i].sc;
		u=w/abs(w);
		w=abs(w)-1;
		cop(mt[mk],m1);
		mpw(k-l);
		for(j=1;j<=mm;j++)
		{
			az[j]=0;
			for(r=1;r<=mm;r++)
			{
				az[j]=(az[j]+a1[r]*mz[j][r])%dv;
			}
		}
		for(j=1;j<=mm;j++)
		{
			a1[j]=az[j];
		}
		if(!fq[w])
		{
			mk^=1<<w;
		}
		fq[w]+=u;
		if(!fq[w])
		{
			mk|=1<<w;
		}
		l=k;
	}
	printf("%lld\n",az[2]);
}