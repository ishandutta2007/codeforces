#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],sq[200069];
pair<pair<bool,long long>,long long> as[200069]; 

int main()
{
	long long t,rr,i,p;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			as[i]={{ch-'0',a[i]},i};
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			p=as[i].sc;
			sq[p]=i;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}