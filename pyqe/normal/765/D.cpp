#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[100069],pst[100069],prs[100069];

int main()
{
	long long i,c=0,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pr[i]=k;
		if(!pst[k])
		{
			c++;
			prs[c]=k;
			pst[k]=c;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(pr[pr[i]]!=pr[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",c);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",pst[pr[i]]," \n"[i==n]);
	}
	for(i=1;i<=c;i++)
	{
		printf("%lld%c",prs[i]," \n"[i==c]);
	}
}