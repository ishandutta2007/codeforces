#include <bits/stdc++.h>

using namespace std;

const long long ub=10,vy[4]={-1,0,1,0},vx[4]={0,-1,0,1};
long long n,m,nn=0,nn2=0,a[400069],a2[400069],ex[400069],ex2[400069];
bitset<400069> vtd;

inline void ad(long long p)
{
	if(!vtd[p])
	{
		vtd[p]=1;
		nn2++;
		ex2[nn2]=p;
	}
}

inline bool chk(long long p)
{
	long long im,y=p/m,x=p%m,yy,xx,pp;
	
	if(a2[p]==1)
	{
		return 1;
	}
	for(im=0;im<4;im++)
	{
		yy=y+vy[im];
		xx=x+vx[im];
		pp=yy*m+xx;
		if(yy>=0&&yy<n&&xx>=0&&xx<m&&a2[pp]<a2[p])
		{
			break;
		}
	}
	return im<4;
}

int main()
{
	long long i,j,r,im,y,x,p,yy,xx,pp,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			scanf("%lld",a+p);
			a2[p]=a[p];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p=i*m+j;
			if(a[p]!=1)
			{
				for(im=0;im<4;im++)
				{
					yy=i+vy[im];
					xx=j+vx[im];
					pp=yy*m+xx;
					if(yy>=0&&yy<n&&xx>=0&&xx<m&&a[pp]<a[p])
					{
						break;
					}
				}
				if(im>=4)
				{
					nn++;
					if(nn>ub)
					{
						printf("2\n");
						return 0;
					}
					ex[nn]=p;
					ad(p);
					for(im=0;im<4;im++)
					{
						yy=i+vy[im];
						xx=j+vx[im];
						pp=yy*m+xx;
						if(yy>=0&&yy<n&&xx>=0&&xx<m)
						{
							ad(pp);
						}
					}
				}
			}
		}
	}
	if(!nn)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=nn2;i++)
	{
		for(j=0;j<n*m;j++)
		{
			if(!(vtd[j]&&j<=ex2[i]))
			{
				swap(a2[ex2[i]],a2[j]);
				if(!chk(j))
				{
					swap(a2[ex2[i]],a2[j]);
					continue;
				}
				y=j/m;
				x=j%m;
				for(im=0;im<4;im++)
				{
					yy=y+vy[im];
					xx=x+vx[im];
					pp=yy*m+xx;
					if(yy>=0&&yy<n&&xx>=0&&xx<m&&!chk(pp))
					{
						break;
					}
				}
				if(im<4)
				{
					swap(a2[ex2[i]],a2[j]);
					continue;
				}
				if(!chk(ex2[i]))
				{
					swap(a2[ex2[i]],a2[j]);
					continue;
				}
				y=ex2[i]/m;
				x=ex2[i]%m;
				for(im=0;im<4;im++)
				{
					yy=y+vy[im];
					xx=x+vx[im];
					pp=yy*m+xx;
					if(yy>=0&&yy<n&&xx>=0&&xx<m&&!chk(pp))
					{
						break;
					}
				}
				if(im<4)
				{
					swap(a2[ex2[i]],a2[j]);
					continue;
				}
				for(r=1;r<=nn;r++)
				{
					if(!chk(ex[r]))
					{
						break;
					}
				}
				z+=r>nn;
				swap(a2[ex2[i]],a2[j]);
			}
		}
	}
	if(z)
	{
		printf("1 %lld\n",z);
	}
	else
	{
		printf("2\n");
	}
}