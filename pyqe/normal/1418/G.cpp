#include <bits/stdc++.h>

using namespace std;

long long n,ls[500069][4];

struct segtree
{
	long long l,r,mn,c,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			mn=0;
			c=1;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mn=min(p[0]->mn,p[1]->mn);
			c=0;
			for(ii=0;ii<2;ii++)
			{
				c+=p[ii]->c*(p[ii]->mn==mn);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mn+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mn=min(p[0]->mn,p[1]->mn);
			c=0;
			for(ii=0;ii<2;ii++)
			{
				c+=p[ii]->c*(p[ii]->mn==mn);
			}
		}
	}
}
sg;

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sg.ud(ls[k][3]+1,ls[k][2],1);
		sg.ud(ls[k][2]+1,ls[k][1],-1);
		sg.ud(ls[k][0]+1,i,1);
		for(j=3;j;j--)
		{
			ls[k][j]=ls[k][j-1];
		}
		ls[k][0]=i;
		z+=(sg.c-(n-i))*!sg.mn;
	}
	printf("%lld\n",z);
}