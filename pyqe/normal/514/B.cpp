#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ys,xs;
pair<long long,long long> as[100069];

int main()
{
	long long i,y,x,gd,z=0;
	
	scanf("%lld%lld%lld",&n,&ys,&xs);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		y-=ys;
		x-=xs;
		if(y<0||(!y&&x<0))
		{
			y*=-1;
			x*=-1;
		}
		gd=__gcd(abs(x),abs(y));
		y/=gd;
		x/=gd;
		as[i]={y,x};
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		z+=i==n||as[i]!=as[i+1];
	}
	printf("%lld\n",z);
}