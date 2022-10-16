#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],ps[2][300069];

int main()
{
	long long i,ii,k,l,w,p,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=n;i;i--)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i]+=ps[ii][i-1];
		}
		p=min(i,n+1-m);
		k=(ps[0][p]-ps[0][max(i-m,0ll)])*i+ps[1][p]-ps[1][max(i-m,0ll)];
		l=min(m,n+1-i);
		w=(max(a[i]-k,0ll)+l-1)/l;
		z+=w;
		ps[0][p]-=w;
		ps[1][p]+=w*(m+p);
	}
	printf("%lld\n",z);
}