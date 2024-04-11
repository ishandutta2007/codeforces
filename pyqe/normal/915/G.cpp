#include <bits/stdc++.h>

using namespace std;

int n,d,pc[2000069],mb[2000069],sq[2000069],pwk,dv=1e9+7;
bitset<2000069> vtd;

int pw(int x,int y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=(long long)pwk*pwk%dv;
	if(y%2)
	{
		pwk=(long long)pwk*x%dv;
	}
	return pwk;
}

int main()
{
	int i,j,z=0;
	
	scanf("%d%d",&d,&n);
	for(i=1;i<=n;i++)
	{
		pc[i]=pw(i,d);
		mb[i]=1;
	}
	for(i=2;i<=n;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=n;j+=i)
			{
				vtd[j]=1;
				mb[j]*=-!!(j/i%i);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			sq[j]=((sq[j]+(pc[j/i]-pc[j/i-1])%dv*mb[i])%dv+dv)%dv;
		}
		sq[i]=(sq[i]+sq[i-1])%dv;
		z=(z+(sq[i]^i))%dv;
	}
	printf("%d\n",z);
}