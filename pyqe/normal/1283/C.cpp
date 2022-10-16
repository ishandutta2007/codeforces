#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sz=0;
bitset<200069> vtd;
vector<long long> v;

int main()
{
	long long i,j,ls;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		vtd[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!a[i]&&!vtd[i])
		{
			v.push_back(i);
			sz++;
		}
	}
	if(sz==1)
	{
		for(j=1,i=1;i<=n;i++)
		{
			if(!a[i])
			{
				for(;vtd[j];j++);
				a[i]=j;
				vtd[j]=1;
				if(i!=v[0])
				{
					ls=i;
				}
			}
		}
		if(a[v[0]]==v[0])
		{
			swap(a[v[0]],a[ls]);
		}
	}
	else
	{
		for(i=0;i<sz;i++)
		{
			a[v[i]]=v[(i+1)%sz];
			vtd[v[(i+1)%sz]]=1;
		}
		for(j=1,i=1;i<=n;i++)
		{
			if(!a[i])
			{
				for(;vtd[j];j++);
				a[i]=j;
				vtd[j]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}