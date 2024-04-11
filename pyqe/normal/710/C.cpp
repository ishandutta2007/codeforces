#include <bits/stdc++.h>

using namespace std;

long long n,cr[2]={2,1};

int main()
{
	long long i,j,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			e=abs(i-(n+1)/2)+abs(j-(n+1)/2)<(n+1)/2;
			printf("%lld%c",cr[e]," \n"[j==n]);
			cr[e]+=2;
		}
	}
}