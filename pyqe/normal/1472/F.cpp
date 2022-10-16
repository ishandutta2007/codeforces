#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ln,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[i]={l,k};
		}
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i+=2)
		{
			if((a[i].fr+a[i].sc)%2==(a[i+1].fr+a[i+1].sc)%2||(i-1&&a[i].fr==a[i-1].fr))
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}