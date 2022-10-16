#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,a[50069][21],fc[21],pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,sm,z=0;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[j][i]);
		}
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=1;i<=m;i++)
	{
		sort(a[i]+1,a[i]+n+1);
		sm=1;
		for(j=1;j<=n;j++)
		{
			sm=sm*max(min(a[i][j],n+1)-j,0ll)%dv;
		}
		z=(z+fc[n]+dv-sm)%dv;
	}
	z=z*pw(fc[n],dv-2)%dv;
	printf("%lld\n",z);
}