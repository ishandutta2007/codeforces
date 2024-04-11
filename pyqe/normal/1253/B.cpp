#include <bits/stdc++.h>

using namespace std;

long long n,ls[1000069],zs=0;
bitset<1000069> vtd;
vector<long long> sq;

int main()
{
	long long i,k,l=0,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if((k>0&&(vtd[k]||ls[k]==zs+1))||(k<0&&!vtd[-k]))
		{
			printf("-1\n");
			return 0;
		}
		if(k>0)
		{
			vtd[k]=1;
			c++;
		}
		else if(k<0)
		{
			vtd[-k]=0;
			c--;
			ls[-k]=zs+1;
		}
		if(!c)
		{
			sq.push_back(i-l);
			zs++;
			l=i;
		}
	}
	if(c)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}