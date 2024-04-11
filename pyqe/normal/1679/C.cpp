#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][100069],fw[2][100069],fi;

inline void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

inline long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

int main()
{
	long long t,rr,ii,ky,y,x,y2,x2;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&y,&x);
		if(ky==1)
		{
			for(ii=0;ii<2;ii++)
			{
				fq[ii][y]++;
				ud(ii,y,fq[ii][y]==1);
				swap(y,x);
			}
		}
		else if(ky==2)
		{
			for(ii=0;ii<2;ii++)
			{
				fq[ii][y]--;
				ud(ii,y,-!fq[ii][y]);
				swap(y,x);
			}
		}
		else
		{
			scanf("%lld%lld",&y2,&x2);
			if(qr(0,y,y2)==y2-y+1||qr(1,x,x2)==x2-x+1)
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