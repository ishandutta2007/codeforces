#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,sq[200069];
pair<long long,long long> a[200069];

struct segtree
{
	long long l,r,ans[2][2],lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l<r)
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void rst()
	{
		lz=0;
		if(l==r)
		{
			ans[0][l%2]=l-l/2;
			ans[1][l%2]=l-l/2;
			ans[0][!(l%2)]=inf;
			ans[1][!(l%2)]=-inf;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->rst();
			}
			for(ii=0;ii<2;ii++)
			{
				ans[0][ii]=min(p[0]->ans[0][ii],p[1]->ans[0][ii]);
				ans[1][ii]=max(p[0]->ans[1][ii],p[1]->ans[1][ii]);
			}
		}
	}
	void blc()
	{
		long long ii,jj,pp;
		
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				for(pp=0;pp<2;pp++)
				{
					p[ii]->ans[jj][pp]+=lz;
				}
			}
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			long long ii,jj;
			
			for(ii=0;ii<2;ii++)
			{
				for(jj=0;jj<2;jj++)
				{
					ans[ii][jj]+=w;
				}
			}
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
			for(ii=0;ii<2;ii++)
			{
				ans[0][ii]=min(p[0]->ans[0][ii],p[1]->ans[0][ii]);
				ans[1][ii]=max(p[0]->ans[1][ii],p[1]->ans[1][ii]);
			}
		}
	}
	long long qr(long long xx,long long yy,long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			if(!xx)
			{
				return inf;
			}
			else
			{
				return -inf;
			}
		}
		else if(l>=lh&&r<=rh)
		{
			return ans[xx][yy];
		}
		else
		{
			blc();
			if(!xx)
			{
				return min(p[0]->qr(xx,yy,lh,rh),p[1]->qr(xx,yy,lh,rh));
			}
			else
			{
				return max(p[0]->qr(xx,yy,lh,rh),p[1]->qr(xx,yy,lh,rh));
			}
		}
	}
}
sg;

int main()
{
	long long i,j,ii,jj,u,k,w,k2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	sg.bd(0,n);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		sg.rst();
		for(j=0,i=1;i<=n;i++)
		{
			w=a[i].fr;
			k=a[i].sc;
			for(;j<n&&a[j+1].fr*u<w*u;)
			{
				j++;
				k2=a[j].sc;
				sg.ud(k2,n,-1);
			}
			for(jj=0;jj<2;jj++)
			{
				sq[k]=max(sq[k],sg.qr(1,jj,k,n)-sg.qr(0,!jj,0,k-1)-jj);
				sq[k]=max(sq[k],sg.qr(1,jj,k,n)-sg.qr(0,jj,0,k-1)-ii);
			}
		}
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}