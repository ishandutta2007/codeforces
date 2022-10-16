#include <bits/stdc++.h>

using namespace std;

int n,ky[169],a[500069],dv=998244353,inf=1e9;
array<array<int,2>,2> m0;

struct segtree
{
	int l,r;
	array<array<int,2>,2> mz;
	segtree *p[2];
	
	array<array<int,2>,2> mrg(array<array<int,2>,2> x,array<array<int,2>,2> y)
	{
		int i,j,r;
		array<array<int,2>,2> tmp;
		
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				tmp[i][j]=0;
				for(r=0;r<2;r++)
				{
					tmp[i][j]=((long long)x[r][j]*y[i][r]+tmp[i][j])%dv;
				}
			}
		}
		return tmp;
	}
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mz[0][0]=1;
			mz[0][1]=0;
			mz[1][0]=1;
			mz[1][1]=0;
		}
		else
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mz=mrg(p[0]->mz,p[1]->mz);
		}
	}
	void ud(int x,array<int,2> w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			int ii;
			
			for(ii=0;ii<2;ii++)
			{
				if(w[ii]!=-inf)
				{
					mz[0][ii]=w[ii];
				}
			}
		}
		else
		{
			int ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			mz=mrg(p[0]->mz,p[1]->mz);
		}
	}
}
sg;

void udd(int x,int w)
{
	a[x]=w;
	sg.ud(x,{ky[a[x]],ky[a[x-1]*10+a[x]]*!!a[x-1]});
	if(x<n)
	{
		sg.ud(x+1,{-inf,ky[a[x]*10+a[x+1]]*!!a[x]});
	}
}

int main()
{
	int t,rr,i,j,k,l;
	string s;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			ky[i+j]++;
		}
	}
	for(i=0;i<2;i++)
	{
		m0[i][i]=1;
	}
	scanf("%d%d",&n,&t);
	sg.bd(1,n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
		udd(i,a[i]);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&k,&l);
		udd(k,l);
		printf("%d\n",sg.mz[0][0]);
	}
}