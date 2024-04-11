#include <bits/stdc++.h>

using namespace std;

long long n,m,nn;
vector<long long> al[100069];
bool bad;

void chk(long long x)
{
	long long i;
	
	bad=0;
	for(i=n/x+1;i<=n;i++)
	{
		if(al[i-n/x]!=al[i])
		{
			bad=1;
			return;
		}
	}
	printf("Yes\n");
	exit(0);
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back((l+n-k)%n);
		al[l].push_back((k+n-l)%n);
	}
	for(i=1;i<=n;i++)
	{
		sort(al[i].begin(),al[i].end());
	}
	for(nn=n,i=2;i*i<=nn;i++)
	{
		if(nn%i==0)
		{
			for(;nn%i==0;nn/=i);
			chk(i);
		}
	}
	if(nn>1)
	{
		chk(nn);
	}
	printf("No\n");
}