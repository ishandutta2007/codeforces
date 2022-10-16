#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n[3],a[5];
pair<long long,long long> ky[7]={{0,0},{1,1},{2,2},{0,3},{1,4},{2,3},{2,4}};

int main()
{
	long long t,rr,i,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",n+i);
		}
		for(i=0;i<5;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<7;i++)
		{
			w=min(n[ky[i].fr],a[ky[i].sc]);
			n[ky[i].fr]-=w;
			a[ky[i].sc]-=w;
		}
		for(i=0;i<5;i++)
		{
			if(a[i])
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