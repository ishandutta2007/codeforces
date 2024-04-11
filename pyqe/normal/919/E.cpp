#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn=0,pst[2][1000069],pwk,dv;

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
	long long i,k,z=0;
	
	scanf("%lld%lld%lld%lld",&n,&m,&dv,&d);
	for(i=1;i<dv;i++)
	{
		if(!nn)
		{
			k=pw(n,i);
			pst[0][k]=i;
			if(k==1)
			{
				nn=i;
			}
		}
		pst[1][m*pw(i,dv-2)%dv]=i;
	}
	for(i=1;i<dv;i++)
	{
		if(pst[0][i])
		{
			k=(pst[1][i]+dv-pst[0][i])*pw(nn,dv-2)%dv*nn+pst[0][i];
			z+=(d-1)/(dv*nn)+(k<=(d-1)%(dv*nn)+1);
		}
	}
	printf("%lld\n",z);
}