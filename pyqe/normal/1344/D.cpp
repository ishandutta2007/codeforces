#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],sq[100069],inf=4e18;
queue<long long> q;

int main()
{
	long long i,k,lh,rh,md,zz,c,lhh,rhh,mdd,zzz;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(lh=-inf,rh=inf;lh<=rh;)
	{
		md=(lh+rh)/2;
		c=0;
		for(i=1;i<=n;i++)
		{
			zzz=0;
			for(lhh=1,rhh=a[i];lhh<=rhh;)
			{
				mdd=(lhh+rhh)/2;
				if(a[i]-mdd*mdd*3+mdd*3-1-md>=0)
				{
					lhh=mdd+1;
					zzz=mdd;
				}
				else
				{
					rhh=mdd-1;
				}
			}
			c+=zzz;
		}
		if(c>=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	c=0;
	for(i=1;i<=n;i++)
	{
		zzz=0;
		for(lhh=1,rhh=a[i];lhh<=rhh;)
		{
			mdd=(lhh+rhh)/2;
			if(a[i]-mdd*mdd*3+mdd*3-1-zz>=0)
			{
				lhh=mdd+1;
				zzz=mdd;
			}
			else
			{
				rhh=mdd-1;
			}
		}
		c+=zzz;
		sq[i]=zzz;
		if(a[i]-sq[i]*sq[i]*3+sq[i]*3-1-zz==0)
		{
			q.push(i);
		}
	}
	for(;c>d;c--)
	{
		k=q.front();
		q.pop();
		sq[k]--;
		if(a[k]-sq[k]*sq[k]*3+sq[k]*3-1-zz==0)
		{
			q.push(k);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}