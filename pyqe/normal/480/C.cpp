#include <bits/stdc++.h>

using namespace std;

long long n,d,st,fn,ps[2][5069],dv=1e9+7;

int main()
{
	long long i,j;
	
	scanf("%lld%lld%lld%lld",&n,&st,&fn,&d);
	if(st<fn)
	{
		st=n+1-st;
		fn=n+1-fn;
	}
	ps[0][st-fn]=1;
	for(i=1;i<=n;i++)
	{
		ps[0][i]=(ps[0][i-1]+ps[0][i])%dv;
	}
	for(i=0;i<d;i++)
	{
		for(j=1;j<=n-fn;j++)
		{
			ps[1][j]=(ps[1][j-1]+ps[0][n-fn]+dv-ps[0][j]+ps[0][j-1]+dv-ps[0][j/2])%dv;
		}
		for(j=1;j<=n-fn;j++)
		{
			ps[0][j]=ps[1][j];
		}
	}
	printf("%lld\n",ps[0][n-fn]);
}