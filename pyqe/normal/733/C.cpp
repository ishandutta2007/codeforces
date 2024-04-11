#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[100069],ky[100069],zs=0,inf=1e18;
pair<long long,bool> sq[100069];

int main()
{
	long long i,j,r,sm=0,ls,e;
	pair<long long,long long> mxe;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",ky+i);
		sm-=ky[i];
	}
	if(sm)
	{
		printf("NO\n");
		return 0;
	}
	ls=n+1;
	for(j=m,i=n;i;i--)
	{
		sm+=a[i];
		if(sm>ky[j])
		{
			printf("NO\n");
			return 0;
		}
		else if(sm==ky[j])
		{
			if(ls-i>1)
			{
				mxe={-inf,-1};
				for(r=i;r<ls;r++)
				{
					if((r+1<ls&&a[r+1]<a[r])||(r-1>=i&&a[r-1]<a[r]))
					{
						mxe=max(mxe,{a[r],r});
					}
				}
				e=mxe.sc;
				if(e==-1)
				{
					printf("NO\n");
					return 0;
				}
				if(e+1<ls&&a[e+1]<a[e])
				{
					zs++;
					sq[zs]={e,1};
				}
				else if(e-1>=i&&a[e-1]<a[e])
				{
					zs++;
					sq[zs]={e,0};
					e--;
				}
				for(r=e;r>i;r--)
				{
					zs++;
					sq[zs]={r,0};
				}
				for(;zs<n+1-i-(m+1-j);)
				{
					zs++;
					sq[zs]={i,1};
				}
			}
			ls=i;
			sm=0;
			j--;
		}
	}
	printf("YES\n");
	for(i=1;i<=zs;i++)
	{
		printf("%lld %c\n",sq[i].fr,"LR"[sq[i].sc]);
	}
}