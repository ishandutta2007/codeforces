#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<1069> vtd[1069];

void ptf(long long y,long long x)
{
	printf("%lld %lld\n",y,x);
	vtd[y][x]=1;
}

int main()
{
	long long i,j,u,y,x,e;
	
	scanf("%lld%lld%lld%lld",&n,&m,&y,&x);
	ptf(y,x);
	ptf(1,x);
	for(i=1;i<=n;i++)
	{
		e=i%2;
		u=!e*2-1;
		for(j=1+(m-1)*e;j!=(m+1)*!e;j+=u)
		{
			if(!vtd[i][j])
			{
				ptf(i,j);
			}
		}
	}
}