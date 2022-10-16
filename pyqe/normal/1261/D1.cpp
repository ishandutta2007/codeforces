#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],fc[200069],d=0,z=1,dv=998244353,pwk;

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
	long long i,j,zz=0,k;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==a[(i+1)%n])
		{
			z=z*m%dv;
		}
		else
		{
			d++;
		}
	}
	for(i=0;i<=d;i++)
	{
		k=pw(2,d-i);
		if((d-i)%2==0)
		{
			k=(k+dv-cb(d-i,(d-i)/2))%dv;
		}
		k=k*pw(2,dv-2)%dv;
		zz=(zz+cb(d,i)*k%dv*pw(m-2,i)%dv)%dv;
	}
	printf("%lld\n",z*zz%dv);
}