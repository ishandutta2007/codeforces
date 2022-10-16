#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				printf("%lld%c",(long long)((j-i)*2<n)-((j-i)*2>n)," \n"[i==n-1&&j==n]);
			}
		}
	}
}