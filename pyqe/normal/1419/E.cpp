#include <bits/stdc++.h>

using namespace std;

long long n,nn,nm,a[200069],ex[200069],fq[2][200069];
vector<long long> sq[2][200069];

int main()
{
	long long t,rr,i,j,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if(i-1)
				{
					nn++;
					a[nn]=i;
				}
				if(n/i!=i)
				{
					nn++;
					a[nn]=n/i;
				}
			}
		}
		sort(a+1,a+nn+1);
		nm=0;
		for(i=1;i<=nn;i++)
		{
			for(j=1;j<=nm;j++)
			{
				if(a[i]%ex[j]==0)
				{
					j=-1;
					break;
				}
			}
			if(j+1)
			{
				nm++;
				ex[nm]=a[i];
				for(ii=0;ii<2;ii++)
				{
					sq[ii][nm].clear();
					fq[ii][nm]=0;
				}
			}
		}
		for(i=1;i<=nn;i++)
		{
			for(j=1;j<=nm;j++)
			{
				if(!fq[1][j]&&a[i]%(ex[j]*ex[j%nm+1])==0)
				{
					sq[1][j].push_back(a[i]);
					fq[1][j]++;
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				for(j=1;j<=nm;j++)
				{
					if(a[i]%ex[j]==0)
					{
						sq[0][j].push_back(a[i]);
						fq[0][j]++;
						break;
					}
				}
			}
		}
		z=0;
		for(i=1;i<=nm;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(j=0;j<fq[ii][i];j++)
				{
					nn--;
					printf("%lld%c",sq[ii][i][j]," \n"[!nn]);
				}
				z+=!fq[ii][i];
			}
		}
		printf("%lld\n",z);
	}
}