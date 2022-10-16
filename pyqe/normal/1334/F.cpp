#include <bits/stdc++.h>

using namespace std;

long long n,m,mxz=1e15,a[500069],wg[500069],as[500069],pst[500069],fw[500069],fi,inf=1e18;

void ud(long long x,long long w)
{
	x++;
	for(fi=x;fi<=m+1;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	x++;
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,j,k,l,p,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",as+i);
		pst[as[i]]=i;
	}
	ud(1,inf);
	for(i=1;i<=n;i++)
	{
		if(pst[a[i]])
		{
			l=qr(pst[a[i]]-1);
		}
		ud(0,wg[i]);
		if(wg[i]>0)
		{
			p=lower_bound(as+1,as+m+1,a[i])-as;
			ud(p,-wg[i]);
		}
		if(pst[a[i]])
		{
			k=qr(pst[a[i]]);
			if(l<k)
			{
				ud(pst[a[i]],l-k);
				ud(pst[a[i]]+1,k-l);
			}
		}
	}
	z=qr(m);
	if(z>=mxz)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n%lld\n",z);
	}
}