#include <bits/stdc++.h>

using namespace std;

long long n,a[7069],sz=0;
vector<long long> v;
map<long long,long long> fq;

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
		if(fq[a[i]]==2)
		{
			v.push_back(a[i]);
			sz++;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<sz;j++)
		{
			if((a[i]&v[j])==a[i])
			{
				z+=k;
				break;
			}
		}
	}
	printf("%lld\n",z);
}