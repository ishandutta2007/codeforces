#include <bits/stdc++.h>

using namespace std;

long long n,m[1000069],fq[1000069],pwk,dv=998244353;
vector<long long> a[1000069];

long long pw(long long x,long long y)
{
	if(!y)
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
	long long i,j,k,z,zzz=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",m+i);
		for(j=0;j<m[i];j++)
		{
			scanf("%lld",&k);
			a[i].push_back(k);
			fq[k]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		z=0;
		for(j=0;j<m[i];j++)
		{
			k=a[i][j];
			z=(z+fq[k]*pw(n,dv-2))%dv;
		}
		zzz=(zzz+z*pw(m[i],dv-2))%dv;
	}
	printf("%lld\n",zzz*pw(n,dv-2)%dv);
}