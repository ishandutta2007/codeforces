#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],vx[60][2],sz[60],ds[100069],b=1e18,c=0;
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	c++;
	ds[x]=c;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ds[l]==0)
		{
			dfs(l);
		}
		else if(ds[l]+1<c)
		{
			b=min(b,c-ds[l]+1);
		}
	}
	ds[x]=0;
	c--;
}

int main()
{
	long long i,it;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(it=0;a[i]>0;it++)
		{
			if(a[i]%2)
			{
				if(sz[it]==2)
				{
					printf("3\n");
					return 0;
				}
				vx[it][sz[it]]=i;
				sz[it]++;
			}
			a[i]/=2;
		}
	}
	for(it=0;it<60;it++)
	{
		if(sz[it]==2)
		{
			al[vx[it][0]].push_back(vx[it][1]);
			al[vx[it][1]].push_back(vx[it][0]);
		}
	}
	for(it=0;it<60;it++)
	{
		if(sz[it]==2&&!vtd[vx[it][0]])
		{
			dfs(vx[it][0]);
		}
	}
	if(b==1000000000000000000)
	{
		b=-1;
	}
	printf("%lld\n",b);
}