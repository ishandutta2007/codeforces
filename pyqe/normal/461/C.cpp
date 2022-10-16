#include <bits/stdc++.h>

using namespace std;

long long nn,n,sh=0,fi,fw[100069];
bool fp=0;

void ud(long long x,long long w)
{
	for(fi=x;fi<=nn;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,ky,k,l,tg,tg2;
	
	scanf("%lld%lld",&nn,&t);
	n=nn;
	for(i=1;i<=n;i++)
	{
		ud(i,1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			if(k>n/2)
			{
				fp^=1;
				k=n-k;
			}
			for(i=1;i<=k;i++)
			{
				tg=i;
				tg2=k*2+1-i;
				if(fp)
				{
					tg=n+1-tg;
					tg2=n+1-tg2;
				}
				tg+=sh;
				tg2+=sh;
				ud(tg2,qr(tg,tg));
			}
			n-=k;
			sh+=k*!fp;
		}
		else if(ky==2)
		{
			scanf("%lld",&l);
			if(fp)
			{
				k=n-k;
				l=n-l;
				swap(k,l);
			}
			k+=sh;
			l+=sh;
			printf("%lld\n",qr(k+1,l));
		}
	}
}