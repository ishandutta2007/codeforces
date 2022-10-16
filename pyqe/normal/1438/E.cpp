#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],msb[200069];
vector<long long> vl[30];

int main()
{
	long long i,j,r,ii,u,k,l,sz,sm,c,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(k=a[i];k>1;k/=2,msb[i]++);
		vl[msb[i]].push_back(i);
	}
	for(i=0;i<30;i++)
	{
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			l=vl[i][j];
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				sm=0;
				c=0;
				for(r=l+u;r>1&&r<n;r+=u)
				{
					sm+=a[r];
					c+=(msb[r]==i)+(msb[r]>i);
					if(c>=2)
					{
						break;
					}
					z+=sm==(a[l]^a[r+u])&&msb[r+u]<=i&&(msb[r+u]<i||!ii);
				}
			}
		}
	}
	printf("%lld\n",z);
}