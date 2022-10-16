#include <bits/stdc++.h>

using namespace std;

long long n,ma=50,a[69];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			if(!i)
			{
				k=0;
			}
			else
			{
				scanf("%lld",&k);
			}
			a[k+1]=(a[k+1]+1)%26;
			for(j=1;j<=ma;j++)
			{
				printf("%c",(char)a[j]+'a');
			}
			printf("\n");
		}
	}
}