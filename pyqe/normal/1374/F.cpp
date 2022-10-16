#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[569],sq[250069],zs,inf=1e18;

void cyc(long long x)
{
	swap(a[x+1],a[x+2]);
	swap(a[x],a[x+1]);
	zs++;
	sq[zs]=x;
}

int main()
{
	long long t,rr,i,j,ii,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		zs=0;
		for(i=1;i<=n-2;i++)
		{
			mne={inf,-1};
			for(j=i;j<=n;j++)
			{
				mne=min(mne,{a[j],j});
			}
			e=mne.sc;
			for(j=e-2;j>=i;j-=2)
			{
				cyc(j);
			}
			if(j==i-1)
			{
				for(ii=0;ii<2;ii++)
				{
					cyc(i);
				}
			}
		}
		if(a[n-1]>a[n])
		{
			for(i=n-2;i;i--)
			{
				cyc(i);
				if(a[i]<=a[i+1])
				{
					break;
				}
			}
			if(!i)
			{
				zs=-1;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}