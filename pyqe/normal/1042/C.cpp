#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
bitset<200069> spc;

int main()
{
	long long i,k,e,ls[2]={0,0};
	bool c=0;
	pair<long long,long long> mxe={-inf,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!k)
		{
			spc[i]=1;
		}
		else if(k<0)
		{
			c^=1;
			mxe=max(mxe,{k,i});
		}
	}
	e=mxe.sc;
	if(c)
	{
		spc[e]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(ls[spc[i]])
		{
			printf("1 %lld %lld\n",ls[spc[i]],i);
		}
		ls[spc[i]]=i;
	}
	if(ls[0]&&ls[1])
	{
		printf("2 %lld\n",ls[1]);
	}
}