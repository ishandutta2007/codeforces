#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[100069];
pair<long long,long long> ti[100069],mxe[100069];
bitset<100069> spc;

int main()
{
	long long i,c=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&ti[i].fr);
		ti[i].sc=i;
	}
	for(i=1;i<=n;i++)
	{
		mxe[a[i]]=max(mxe[a[i]],ti[i]);
	}
	for(i=1;i<=m;i++)
	{
		if(mxe[i].fr)
		{
			spc[mxe[i].sc]=1;
		}
		else
		{
			c++;
		}
	}
	sort(ti+1,ti+n+1);
	for(i=1;i<=n&&c;i++)
	{
		if(!spc[ti[i].sc])
		{
			z+=ti[i].fr;
			c--;
		}
	}
	printf("%lld\n",z);
}