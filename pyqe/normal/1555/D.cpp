#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,ps[2][3][200069];

int main()
{
	long long t,rr,i,j,ii,u,k,l,z;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		k=ch-'a';
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(j=0;j<3;j++)
			{
				ps[ii][j][i]=ps[ii][j][i-1]+(k!=(((i+j)%3)*u+3)%3);
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<3;i++)
			{
				z=min(z,ps[ii][i][l]-ps[ii][i][k-1]);
			}
		}
		printf("%lld\n",z);
	}
}