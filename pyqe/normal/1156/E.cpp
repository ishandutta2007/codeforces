#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],pst[200069],c=0,lh,rh,sg[524288];

long long md(long long l,long long r)
{
	return (l+r)/2;
}

long long bd(long long l,long long r,long long p)
{
	if(l==r)
	{
		sg[p]=a[l];
	}
	else
	{
		sg[p]=max(bd(l,md(l,r),p*2),bd(md(l,r)+1,r,p*2+1));
	}
	return sg[p];
}

long long sm(long long l,long long r,long long p)
{
	if(l>rh||r<lh)
	{
		return -1e9;
	}
	else if(l>=lh&&r<=rh)
	{
		return sg[p];
	}
	else
	{
		return max(sm(l,md(l,r),p*2),sm(md(l,r)+1,r,p*2+1));
	}
}

void dnc(long long l,long long r)
{
	if(r-l+1<=2)
	{
		return;
	}
	long long mx,i;
	
	lh=l;
	rh=r;
	mx=sm(1,n,1);
	if(pst[mx]-l<=r-pst[mx])
	{
		for(i=l;i<pst[mx];i++)
		{
			if(pst[mx-a[i]]>pst[mx]&&pst[mx-a[i]]<=r)
			{
				c++;
			}
		}
	}
	else
	{
		for(i=r;i>pst[mx];i--)
		{
			if(pst[mx-a[i]]<pst[mx]&&pst[mx-a[i]]>=l)
			{
				c++;
			}
		}
	}
	dnc(l,pst[mx]-1);
	dnc(pst[mx]+1,r);
}

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
	}
	bd(1,n,1);
	dnc(1,n);
	printf("%lld\n",c);
}