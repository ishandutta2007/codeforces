#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<569> a[569];

int main()
{
	long long t,rr,i,j,ii,jj,c,z;
	bool bad,bad2;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		bad=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
				bad|=!a[i][j];
				z+=a[i][j];
			}
		}
		bad2=0;
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				c=0;
				for(ii=0;ii<2;ii++)
				{
					for(jj=0;jj<2;jj++)
					{
						c+=!a[i+ii][j+jj];
					}
				}
				bad2|=c>=2;
			}
		}
		printf("%lld\n",z-!bad-!bad2);
	}
}