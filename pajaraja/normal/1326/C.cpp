#include <bits/stdc++.h>
#define MAXN 200007
#define MOD 998244353
using namespace std;
int p[MAXN];
int main()
{
	int n,k;
	long long lst=0,br=1,rez=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		long long t;
		scanf("%lld",&t);
		if(t>n-k)
		{
			rez+=t;
			if(lst) br=(br*((long long)i-lst))%MOD;
			lst=i;
		}
	}
	printf("%lld %lld",rez,br);
}