#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ys,xs,fq[4];

int main()
{
	long long i,y,x,ky[4]={-1,0,1,0},kx[4]={0,1,0,-1};
	pair<long long,long long> mx={-1e18,-1};
	
	scanf("%lld%lld%lld",&n,&ys,&xs);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&y,&x);
		if(y<ys)
		{
			fq[0]++;
		}
		if(x>xs)
		{
			fq[1]++;
		}
		if(y>ys)
		{
			fq[2]++;
		}
		if(x<xs)
		{
			fq[3]++;
		}
	}
	for(i=0;i<4;i++)
	{
		mx=max(mx,{fq[i],i});
	}
	printf("%lld\n%lld %lld\n",mx.fr,ys+ky[mx.sc],xs+kx[mx.sc]);
}