#include <bits/stdc++.h>

using namespace std;

long long n,m,inf=1e18;
bitset<3> a[1000069];

int main()
{
	long long i,j,ii,k,mk,mkk,c,mn,cc,z=inf;
	bool iv;
	string s;
	
	scanf("%lld%lld",&n,&m);
	if(min(n,m)>=4)
	{
		printf("-1\n");
		return 0;
	}
	iv=n<m;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			k=s[j-1]-'0';
			if(iv)
			{
				swap(i,j);
			}
			a[i][j-1]=k;
			if(iv)
			{
				swap(i,j);
			}
		}
	}
	if(iv)
	{
		swap(n,m);
	}
	for(mk=0;mk<1ll<<m-1;mk++)
	{
		c=0;
		for(i=1;i<=n;i++)
		{
			mkk=mk;
			if(m-1)
			{
				mkk^=i%2<<m-2;
			}
			mn=inf;
			for(ii=0;ii<2;ii++)
			{
				cc=0;
				for(j=0;j<m;j++)
				{
					cc+=a[i][j]==((mkk>>j&1)^ii);
				}
				mn=min(mn,cc);
			}
			c+=mn;
		}
		z=min(z,c);
	}
	printf("%lld\n",z);
}