#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[300069],sp[20][300069],sz=0,z[100069];
vector<pair<long long,long long>> v;

void bd()
{
	long long i,j;
	
	for(i=1;i<=n*3;i++)
	{
		sp[0][i]=a[i];
	}
	for(i=1;(1<<i)-1<n*3;i++)
	{
		for(j=1;j<=n*3-(1<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<i-1)]);
		}
	}
}

long long qr(long long lh,long long rh)
{
	long long ln=rh-lh+1,k,lg=0;
	
	for(k=ln;k>1;k/=2,lg++);
	return min(sp[lg][lh],sp[lg][rh-(1<<lg)+1]);
}

int main()
{
	long long i,j,lh,rh,md,zz,mn=1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i+n]=a[i];
		a[i+n+n]=a[i];
	}
	bd();
	for(i=1;i<=n*3;i++)
	{
		lh=i;
		rh=n*3;
		zz=-1;
		for(;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(i,md)*2<a[i])
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		if(zz!=-1)
		{
			v.push_back({i,zz});
			sz++;
		}
	}
	sort(v.begin(),v.end(),greater<pair<long long,long long>>());
	for(j=0,i=n;i>0;i--)
	{
		for(;j<sz&&v[j].fr>=i;j++)
		{
			mn=min(mn,v[j].sc);
		}
		if(mn==1000000000000000000)
		{
			z[i]=-1;
		}
		else
		{
			z[i]=mn-i;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}