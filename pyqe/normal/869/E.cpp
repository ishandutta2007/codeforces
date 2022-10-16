#include <bits/stdc++.h>

using namespace std;

long long n,m,a[2569][2569],fw[2569][2569],fi,fj;

void ud(long long y,long long x,long long w)
{
	for(fi=y;fi<=n;fi+=fi&-fi)
	{
		for(fj=x;fj<=m;fj+=fj&-fj)
		{
			fw[fi][fj]^=w;
		}
	}
}

long long qr(long long y,long long x)
{
	long long z=0;
	
	for(fi=y;fi;fi-=fi&-fi)
	{
		for(fj=x;fj;fj-=fj&-fj)
		{
			z^=fw[fi][fj];
		}
	}
	return z;
}

int main()
{
	long long t,rr,ky,y,x,y2,x2;
	
	srand(time(NULL));
	scanf("%lld%lld%lld",&n,&m,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&ky,&y,&x,&y2,&x2);
		if(ky==1)
		{
			a[y][x]=(long long)rand()<<45^(long long)rand()<<30^rand()<<15^rand();
			ud(y,x,a[y][x]);
			ud(y2+1,x,a[y][x]);
			ud(y,x2+1,a[y][x]);
			ud(y2+1,x2+1,a[y][x]);
		}
		else if(ky==2)
		{
			ud(y,x,a[y][x]);
			ud(y2+1,x,a[y][x]);
			ud(y,x2+1,a[y][x]);
			ud(y2+1,x2+1,a[y][x]);
		}
		else
		{
			if(qr(y,x)==qr(y2,x2))
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}