#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[169];
map<pair<long long,long long>,long long> fq;

int main()
{
	long long t,rr,i,j,y,x,gd,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=n-1;
		for(i=1;i<=n;i++)
		{
			fq.clear();
			for(j=1;j<=n;j++)
			{
				if(j!=i)
				{
					y=a[i]-a[j];
					x=i-j;
					gd=__gcd(abs(x),abs(y));
					y/=gd;
					x/=gd;
					if(x<0)
					{
						y*=-1;
						x*=-1;
					}
					fq[{y,x}]++;
					z=min(z,n-1-fq[{y,x}]);
				}
			}
		}
		printf("%lld\n",z);
	}
}