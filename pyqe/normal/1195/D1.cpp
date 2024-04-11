#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][10],sm[11][10],fq[11],d[100069],dv=998244353;

int main()
{
	long long i,j,r,k,kk,p,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;k>0;j++,k/=10)
		{
			a[i][j]=k%10;
		}
		d[i]=j;
		fq[d[i]]++;
		for(j=0;j<d[i];j++)
		{
			sm[d[i]][j]+=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=10;j++)
		{
			k=1;
			for(r=0;r<j+d[i];r++,k=k*10%dv)
			{
				if(r<min(j,d[i])*2)
				{
					p=r/2;
					if(r%2==0)
					{
						kk=fq[j]*a[i][p]*k%dv;
					}
					else
					{
						kk=sm[j][p]*k%dv;
					}
				}
				else if(j<d[i])
				{
					p=r-j;
					kk=fq[j]*a[i][p]*k%dv;
				}
				else if(d[i]<j)
				{
					p=r-d[i];
					kk=sm[j][p]*k%dv;
				}
				z=(z+kk)%dv;
			}
		}
	}
	printf("%lld\n",z);
}