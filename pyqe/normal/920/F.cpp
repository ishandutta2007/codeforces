#include <bits/stdc++.h>

using namespace std;

long long n,dr[1000069],a[300069],fw[300069],dsu[300069],fi,mxa=1e6;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
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
	long long t,rr,i,j,ky,k,l,c;
	
	for(i=1;i<=mxa;i++)
	{
		dr[i]=1;
	}
	for(i=2;i<=mxa;i++)
	{
		if(dr[i]==1)
		{
			for(j=i;j<=mxa;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				dr[j]*=c+1;
			}
		}
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ud(i,a[i]);
	}
	for(i=1;i<=n+1;i++)
	{
		dsu[i]=i;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			for(i=k;i<=l;i=fd(i+1))
			{
				ud(i,-a[i]);
				a[i]=dr[a[i]];
				ud(i,a[i]);
				if(dr[a[i]]==a[i])
				{
					dsu[i]=fd(i+1);
				}
			}
		}
		else if(ky==2)
		{
			printf("%lld\n",qr(k,l));
		}
	}
}