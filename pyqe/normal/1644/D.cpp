#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=998244353;
long long n,m,d,nn,vi[2][200069];
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,ii,y,x,c[2],z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&d,&nn);
		for(i=1;i<=nn;i++)
		{
			scanf("%lld%lld",&y,&x);
			a[i]={y,x};
		}
		z=1;
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
		}
		for(i=nn;i;i--)
		{
			y=a[i].fr;
			x=a[i].sc;
			if(c[0]<n&&c[1]<m&&(vi[0][y]<rr||vi[1][x]<rr))
			{
				z=z*d%dv;
			}
			for(ii=0;ii<2;ii++)
			{
				c[ii]+=vi[ii][y]<rr;
				vi[ii][y]=rr;
				swap(y,x);
			}
		}
		printf("%lld\n",z);
	}
}