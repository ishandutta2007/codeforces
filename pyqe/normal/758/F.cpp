#include <bits/stdc++.h>

using namespace std;

long long n,lb,rb,ky[10000069],ps[10000069],pwk;
bitset<10000069> vtd;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=min(pwk*pwk,rb+1);
	if(y%2)
	{
		pwk=min(pwk*x,rb+1);
	}
	return pwk;
}

int main()
{
	long long i,j,r,k,c,z=0;
	
	scanf("%lld%lld%lld",&n,&lb,&rb);
	if(n==1)
	{
		printf("%lld\n",rb-lb+1);
		return 0;
	}
	for(i=1;i<=rb;i++)
	{
		ky[i]=i;
	}
	for(i=2;i<=rb;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=rb;j+=i)
			{
				vtd[j]=1;
				for(c=0;ky[j]%i==0;ky[j]/=i,c++);
				for(r=0;r<c%(n-1);r++,ky[j]*=i);
			}
		}
	}
	for(i=1;1;i++)
	{
		k=pw(i,n-1);
		if(k>rb)
		{
			break;
		}
		ps[k]++;
	}
	for(i=1;i<=rb;i++)
	{
		ps[i]+=ps[i-1];
	}
	for(i=lb;i<=rb;i++)
	{
		z+=ps[rb/ky[i]]-ps[(lb-1)/ky[i]]-1;
	}
	printf("%lld\n",z);
}