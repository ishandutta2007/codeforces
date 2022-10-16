#include <bits/stdc++.h>

using namespace std;

long long n,fw[2][200069],fwp,pst[200069];

void ud(long long y,long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[y][fwp]+=w;
	}
}

long long qr(long long y,long long lh,long long rh)
{
	long long z=0;
	
	if(lh>rh)
	{
		swap(lh,rh);
	}
	//cout<<lh<<" "<<rh<<endl;
	for(fwp=rh;fwp;fwp-=fwp&-fwp)
	{
		z+=fw[y][fwp];
	}
	for(fwp=lh-1;fwp;fwp-=fwp&-fwp)
	{
		z-=fw[y][fwp];
	}
	return z;
}

long long bs(long long x,long long w,long long u)
{
	long long lh=0,rh=n,md,zz=-1;
	
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		//cout<<x<<" "<<md<<" "<<u<<endl;
		if(qr(0,x,max(min(x+md*u,n),1ll))>=w)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	if(zz==-1)
	{
		return -1;
	}
	return x+zz*u;
}

int main()
{
	long long i,k,l,p,z=0,ds;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	for(i=1;i<=n;i++)
	{
		p=qr(0,1,pst[i])+1;
		k=bs(pst[i],i/2-p,1);
		if(k!=-1)
		{
			z+=qr(1,pst[i],k);
		}
		k=bs(pst[i],i/2-i+p,-1);
		if(k!=-1)
		{
			z+=qr(1,k,pst[i]);
		}
		k=bs(pst[i],1,-1);
		if(k!=-1)
		{
			l=qr(1,k,k);
			ud(1,k,pst[i]-k-1-l);
			z+=(pst[i]-k-1-l)*min(p-1,i-p+1);
		}
		k=bs(pst[i],1,1);
		if(k!=-1)
		{
			ud(1,pst[i],k-pst[i]-1);
			z+=(k-pst[i]-1)*min(p,i-p);
		}
		z+=qr(0,pst[i],n);
		ud(0,pst[i],1);
		ud(1,pst[i],ds);
		printf("%lld%c",z," \n"[i==n]);
	}
}