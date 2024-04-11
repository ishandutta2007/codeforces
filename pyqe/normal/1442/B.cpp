#include <bits/stdc++.h>

using namespace std;

long long n,m,pst[200069],od[200069],dv=998244353;

int main()
{
	long long t,rr,i,u,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pst[k]=i;
			od[i]=0;
		}
		od[0]=m+1;
		od[n+1]=m+1;
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&k);
			od[pst[k]]=i;
		}
		z=1;
		for(i=1;i<=n;i++)
		{
			if(od[i])
			{
				c=0;
				for(u=-1;u<=1;u+=2)
				{
					c+=od[i+u]<od[i];
				}
				z=z*c%dv;
			}
		}
		printf("%lld\n",z);
	}
}