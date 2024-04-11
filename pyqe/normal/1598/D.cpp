#include <bits/stdc++.h>

using namespace std;

long long n,a[200069][2],fq[2][200069];
map<long long,long long> fq2[200069];

int main()
{
	long long t,rr,i,ii,k,l,c[5],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				fq[ii][i]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			fq2[i].clear();
		}
		for(i=0;i<5;i++)
		{
			c[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[i][0]=k;
			a[i][1]=l;
			fq[0][k]++;
			fq[1][l]++;
			c[0]+=fq2[k][l]*(n-2);
			c[4]+=fq2[k][l]*(fq2[k][l]-1);
			fq2[k][l]++;
		}
		for(i=1;i<=n;i++)
		{
			k=a[i][0];
			l=a[i][1];
			c[1]+=(fq[0][k]-fq2[k][l])*(fq[1][l]-fq2[k][l]);
		}
		for(i=1;i<=n;i++)
		{
			k=a[i][0];
			l=a[i][1];
			c[2]+=fq2[k][l]*(fq2[k][l]-1)*(fq[0][k]-fq2[k][l]);
			c[3]+=fq2[k][l]*(fq2[k][l]-1)*(fq[1][l]-fq2[k][l]);
			fq2[k][l]=0;
		}
		z=n*(n-1)*(n-2)/6-c[0]-c[1]+c[4]*2;
		printf("%lld\n",z);
	}
}