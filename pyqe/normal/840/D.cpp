#include <bits/stdc++.h>

using namespace std;

int n,nn=0,pst[300069],la[6900069],ra[6900069],sm[6900069],p[6900069][2],inf=1e9;

void cop(int x,int y)
{
	int ii;
	
	la[y]=la[x];
	ra[y]=ra[x];
	sm[y]=sm[x];
	for(ii=0;ii<2;ii++)
	{
		p[y][ii]=p[x][ii];
	}
}

void bd(int ix,int lh,int rh)
{
	la[ix]=lh;
	ra[ix]=rh;
	if(la[ix]==ra[ix])
	{
		sm[ix]=0;
	}
	else
	{
		int ii,md=(la[ix]+ra[ix])/2;
		
		sm[ix]=0;
		for(ii=0;ii<2;ii++)
		{
			nn++;
			p[ix][ii]=nn;
			bd(nn,!ii?la[ix]:md+1,!ii?md:ra[ix]);
			sm[ix]+=sm[p[ix][ii]];
		}
	}
}

void ud(int ix,int x,int w)
{
	if(la[ix]>=x&&ra[ix]<=x)
	{
		sm[ix]+=w;
	}
	else
	{
		int ii;
		
		sm[ix]=0;
		for(ii=0;ii<2;ii++)
		{
			if(!(la[p[ix][ii]]>x||ra[p[ix][ii]]<x))
			{
				nn++;
				cop(p[ix][ii],nn);
				p[ix][ii]=nn;
				ud(nn,x,w);
			}
			sm[ix]+=sm[p[ix][ii]];
		}
	}
}

int qr(int ix,int iy,int w)
{
	if(sm[ix]-sm[iy]<=w)
	{
		return inf;
	}
	else if(la[ix]==ra[ix])
	{
		return la[ix];
	}
	else
	{
		return min(qr(p[ix][0],p[iy][0],w),qr(p[ix][1],p[iy][1],w));
	}
}

int main()
{
	int t,rr,i,k,l,w,z;
	
	scanf("%d%d",&n,&t);
	nn++;
	pst[0]=nn;
	bd(nn,1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		nn++;
		pst[i]=nn;
		cop(pst[i-1],nn);
		ud(nn,k,1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d",&k,&l,&w);
		z=qr(pst[l],pst[k-1],(l-k+1)/w);
		if(z==inf)
		{
			z=-1;
		}
		printf("%d\n",z);
	}
}