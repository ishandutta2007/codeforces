#include <bits/stdc++.h>

using namespace std;

long long n,fw[2][2][1069][1069],fi,fj;

void ud(long long y,long long x,long long w)
{
	long long yy=y%2,xx=x%2;
	
	y/=2;
	x/=2;
	for(fi=y;fi<=n+1;fi+=fi&-fi)
	{
		for(fj=x;fj<=n+1;fj+=fj&-fj)
		{
			fw[yy][xx][fi][fj]^=w;
		}
	}
}

long long qr(long long y,long long x)
{
	long long yy=y%2,xx=x%2,z=0;
	
	y/=2;
	x/=2;
	for(fi=y;fi;fi-=fi&-fi)
	{
		for(fj=x;fj;fj-=fj&-fj)
		{
			z^=fw[yy][xx][fi][fj];
		}
	}
	return z;
}

void udd(long long y,long long x,long long y2,long long x2,long long w)
{
	y2-=y2%2!=y%2;
	x2-=x2%2!=x%2;
	if(y>y2||x>x2)
	{
		return;
	}
	ud(y,x,w);
	ud(y2+2,x,w);
	ud(y,x2+2,w);
	ud(y2+2,x2+2,w);
}

int main()
{
	long long t,rr,ii,jj,ky,y,x,y2,x2,w;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&ky,&y,&x,&y2,&x2);
		y++;
		x++;
		y2++;
		x2++;
		if(ky==1)
		{
			printf("%lld\n",qr(y2,x2)^qr(y-1,x2)^qr(y2,x-1)^qr(y-1,x-1));
		}
		else
		{
			scanf("%lld",&w);
			udd(y,x,y2-1,x2-1,w);
			for(ii=0;ii<2;ii++)
			{
				if((y2-y)%2==0)
				{
					udd(y2+ii,x,n+1,x2-1,w);
				}
				if((x2-x)%2==0)
				{
					udd(y,x2+ii,y2-1,n+1,w);
				}
				if((y2-y)%2==0&&(x2-x)%2==0)
				{
					for(jj=0;jj<2;jj++)
					{
						udd(y2+ii,x2+jj,n+1,n+1,w);
					}
				}
			}
		}
	}
}