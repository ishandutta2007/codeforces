#include <bits/stdc++.h>

using namespace std;

const long long d=30;
long long n,nn,fq[100069],fq2[100069][30],ps[100069];

int main()
{
	long long t,rr,i,j,k,l,w,p,lh,rh,md,zz,e,z=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;n;i++)
	{
		w=min((i+1)/2,n);
		z+=i*w;
		fq[i+1-w*2]++;
		fq[i+1]--;
		n-=w;
	}
	nn=i-1;
	for(i=2;i<nn+d;i++)
	{
		fq[i]+=fq[i-2];
	}
	for(i=0;i<nn;i++)
	{
		l=0;
		for(j=0;j<d;j++)
		{
			k=min(1ll<<j,fq[i]);
			fq2[i+j][j]+=k-l;
			l=k;
		}
	}
	for(i=0;i<nn+d;i++)
	{
		ps[i+1]=ps[i];
		for(j=0;j<d;j++)
		{
			ps[i+1]+=fq2[i][j];
		}
	}
	printf("%lld\n",z);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		p=lower_bound(ps+1,ps+nn+d+1,k)-ps-1;
		k-=ps[p];
		for(lh=0,rh=(1ll<<d)-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			w=fq2[p][0];
			for(j=1;j<d;j++)
			{
				w+=min(md+(1ll<<d-j)>>d-j+1,fq2[p][j]);
			}
			if(w>=k)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		if(!zz)
		{
			e=0;
		}
		else
		{
			for(j=1;zz>>d-j<<d-j!=zz;j++);
			e=j;
		}
		
		z=(zz+(1ll<<d)>>d-e)+p-e;
		printf("%lld\n",z);
	}
}