#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=0,nn[3];
pair<long long,long long> a[100069];

long long cb(long long x,long long y)
{
	if(x<y)
	{
		return 0;
	}
	long long i,z=1;
	
	for(i=x;i>x-y;i--)
	{
		z*=i;
	}
	for(i=1;i<=y;i++)
	{
		z/=i;
	}
	return z;
}

int main()
{
	long long i,j,r,k,w,c[3]={0,0,0},ml,z=0;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",nn+i);
	}
	for(i=0;i<3;i++)
	{
		for(j=1;j<=nn[i];j++)
		{
			scanf("%lld",&k);
			a[n+j]={k,i};
		}
		n+=nn[i];
	}
	sort(a+1,a+n+1);
	for(j=0,i=1;i<=n;i++)
	{
		w=a[i].fr;
		k=a[i].sc;
		c[k]--;
		for(;j<n&&a[j+1].fr<=w*2;j++,c[a[j].sc]++);
		ml=1;
		for(r=0;r<3;r++)
		{
			ml*=cb(c[r],r+1-(r==k));
		}
		z+=ml;
	}
	printf("%lld\n",z);
}