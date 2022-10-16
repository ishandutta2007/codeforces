#include <bits/stdc++.h>

using namespace std;

long long n,d,c=0,sz=0;
vector<long long> v;
map<long long,vector<long long>> fz;

void opt(long long x)
{
	c++;
	if(c>1)
	{
		printf(" ");
	}
	printf("%lld",x);
	if(c==100000)
	{
		printf("\n");
		exit(0);
	}
}

void bf(long long x,long long y)
{
	if(y==0||x==1)
	{
		opt(x);
	}
	else
	{
		long long i,sz=fz[x].size();
		
		if(sz==2)
		{
			for(i=0;i<y;i++)
			{
				opt(1);
			}
			opt(x);
		}
		else
		{
			for(i=0;i<sz;i++)
			{
				bf(fz[x][i],y-1);
			}
		}
	}
}

int main()
{
	long long i,j;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			sz++;
		}
	}
	for(i--;i>0;i--)
	{
		if(i*i!=n&&n%i==0)
		{
			v.push_back(n/i);
			sz++;
		}
	}
	for(i=0;i<sz;i++)
	{
		for(j=0;v[j]<=v[i]/v[j];j++)
		{
			if(v[i]%v[j]==0)
			{
				fz[v[i]].push_back(v[j]);
			}
		}
		for(j--;j>=0;j--)
		{
			if(v[j]*v[j]!=v[i]&&v[i]%v[j]==0)
			{
				fz[v[i]].push_back(v[i]/v[j]);
			}
		}
	}
	bf(n,d);
	printf("\n");
}