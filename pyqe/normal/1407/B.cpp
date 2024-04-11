#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1069],ls[1069],inf=1e18;

int main()
{
	long long t,rr,i,j,gd,e;
	pair<long long,long long> mxe;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		gd=0;
		for(i=1;i<=n;i++)
		{
			mxe={-inf,-1};
			for(j=1;j<=n;j++)
			{
				if(ls[j]<rr)
				{
					mxe=max(mxe,{__gcd(gd,a[j]),j});
				}
			}
			e=mxe.sc;
			printf("%lld%c",a[e]," \n"[i==n]);
			gd=__gcd(gd,a[e]);
			ls[e]=rr;
		}
	}
}