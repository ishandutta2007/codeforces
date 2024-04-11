#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,fc[200069],dv=1e9+7,pwk,dp[2069];
pair<long long,long long> a[2069];

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long cb(long long x,long long y)
{
	return fc[x]*pw(fc[y]*fc[x-y]%dv,dv-2)%dv;
}

int main()
{
	long long i,z=0,j;
	
	fc[0]=1;
	for(i=1;i<=200000;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	scanf("%lld%lld%lld",&n,&m,&d);
	a[0]=mp(1,1);
	dp[0]=1;
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a,a+d+1);
	for(i=0;i<=d;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j].sc<=a[i].sc)
			{
				dp[i]-=dp[j]*cb(a[i].fr+a[i].sc-a[j].fr-a[j].sc,a[i].fr-a[j].fr)%dv;
				dp[i]%=dv;
			}
		}
		z+=dp[i]*cb(n+m-a[i].fr-a[i].sc,n-a[i].fr)%dv;
		z%=dv;
	}
	z=(z+dv)%dv;
	printf("%lld\n",z);
}