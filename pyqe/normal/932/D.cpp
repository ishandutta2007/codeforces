#include <bits/stdc++.h>

using namespace std;

long long n=1,a[400069],pr[400069][19],dp[400069][19],m[400069],prr[400069][19],sm[400079][19],mm[400069];

int main()
{
	long long t,rr,i,ky,k,l,z,ls=0;
	
	mm[1]=1;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		k^=ls;
		l^=ls;
		if(ky==1)
		{
			n++;
			a[n]=l;
			pr[n][0]=k;
			dp[n][0]=a[k];
			for(i=1;i-1<m[pr[n][i-1]];i++)
			{
				pr[n][i]=pr[pr[n][i-1]][i-1];
				dp[n][i]=max(dp[n][i-1],dp[pr[n][i-1]][i-1]);
			}
			m[n]=i;
			k=n;
			for(i=m[n]-1;i>=0;i--)
			{
				if(i<m[k]&&dp[k][i]<a[n])
				{
					k=pr[k][i];
				}
			}
			sm[n][0]=a[n];
			prr[n][0]=pr[k][0];
			for(i=1;i-1<mm[prr[n][i-1]];i++)
			{
				prr[n][i]=prr[prr[n][i-1]][i-1];
				sm[n][i]=sm[n][i-1]+sm[prr[n][i-1]][i-1];
			}
			mm[n]=i;
		}
		else if(ky==2)
		{
			ls=0;
			z=0;
			for(i=mm[k]-1;i>=0;i--)
			{
				if(i<mm[k]&&z+sm[k][i]<=l)
				{
					ls+=1<<i;
					z+=sm[k][i];
					k=prr[k][i];
				}
			}
			printf("%lld\n",ls);
		}
	}
}