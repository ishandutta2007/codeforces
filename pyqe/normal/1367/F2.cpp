#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fw[2][200069],fi,pr[2][200069],inf=1e18;
pair<long long,long long> a[200069];

void ud(long long xx,long long x,long long w)
{
	if(!x)
	{
		return;
	}
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long lh,long long rh)
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
	long long t,rr,i,j,ii,u,k,l,ls,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]={k,i};
		}
		sort(a+1,a+n+1);
		a[n+1].sc=n+1;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				k=a[i].fr;
				pr[ii][i]=pr[ii][i-u];
				if(i==1+(n-1)*ii||k!=a[i-u].fr)
				{
					pr[ii][i]=i;
				}
				fw[ii][i]=0;
			}
			pr[ii][n+1]=n+1;
		}
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			if(i==1||a[i].sc<a[i-1].sc)
			{
				if(i-1)
				{
					for(j=pr[0][ls-1];j<ls;j++)
					{
						l=a[j].sc;
						ud(0,l,-1);
					}
				}
				ls=i;
				for(j=pr[0][ls-1];j<ls;j++)
				{
					l=a[j].sc;
					ud(0,l,1);
				}
			}
			if(pr[0][i]==i)
			{
				if(i>1)
				{
					for(j=i;j<=pr[1][i];j++)
					{
						l=a[j].sc;
						ud(1,l,-1);
					}
				}
				for(j=pr[1][i]+1;j<=pr[1][pr[1][i]+1];j++)
				{
					l=a[j].sc;
					ud(1,l,1);
				}
			}
			k=a[i].fr;
			l=a[i].sc;
			mx=max(mx,i-pr[0][i]+1+qr(1,l+1,n));
			mx=max(mx,i-ls+1+qr(0,1,a[ls].sc-1)+qr(1,l+1,n)*(pr[1][i]==i));
		}
		printf("%lld\n",n-mx);
	}
}