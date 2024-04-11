#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],fq[200069];
vector<long long> vl[200069];

int main()
{
	long long i,j,k,w,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		k=a[i]%m;
		vl[k].push_back(i);
		fq[k]++;
	}
	for(j=0,i=0;i<m;i++)
	{
		for(;fq[i]>n/m;fq[i]--)
		{
			k=vl[i][fq[i]-1];
			for(j=max(j,i);fq[j%m]>=n/m;j++);
			w=j-i;
			z+=w;
			a[k]+=w;
			fq[j%m]++;
		}
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}