#include <bits/stdc++.h>

using namespace std;

long long n,d,ys,xs;

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&ys,&xs);
		ys--;
		xs--;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				z=(i+j)%d==(ys+xs)%d;
				printf("%c",".X"[z]);
			}
			printf("\n");
		}
	}
}