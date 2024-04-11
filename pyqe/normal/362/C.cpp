#include <bits/stdc++.h>

using namespace std;

long long n,a[5069],pst[5069],fw[5069],fi;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,j,k,mx=0,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]++;
		pst[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			fw[j]=0;
		}
		for(j=a[i]-1;j;j--)
		{
			if(pst[j]>i)
			{
				k=qr(pst[j])*2+1;
				if(k>mx)
				{
					mx=k;
					c=0;
				}
				c+=k==mx;
				ud(pst[j],1);
			}
		}
	}
	mx*=-1;
	for(i=1;i<=n;i++)
	{
		for(j=i;a[j]<a[j-1];j--)
		{
			swap(a[j],a[j-1]);
			mx++;
		}
	}
	printf("%lld %lld\n",mx,c);
}