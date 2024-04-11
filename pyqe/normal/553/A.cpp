#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],ps[1069],fc[1069],pwk,dv=1e9+7;

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

int main()
{
	long long i,j,c=0,z;
	
	fc[0]=1;
	for(i=1;i<=1000;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	scanf("%lld",&n);
	for(i=n;i>0;i--)
	{
		scanf("%lld",a+i);
	}
	ps[0]=1;
	for(i=1;i<=n;i++)
	{
		c+=a[i]-1;
		for(j=1;j<=c;j++)
		{
			ps[j]=(ps[j]+ps[j-1]*(c-j+1))%dv;
		}
	}
	z=ps[c];
	for(i=1;i<=n;i++)
	{
		z=z*pw(fc[a[i]-1],dv-2)%dv;
	}
	printf("%lld\n",z);
}