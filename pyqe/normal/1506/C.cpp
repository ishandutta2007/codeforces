#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][269];

int main()
{
	long long t,rr,i,j,r,ii,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n[ii]=s.length();
			for(i=1;i<=n[ii];i++)
			{
				a[ii][i]=s[i-1]-'a';
			}
		}
		z=0;
		for(i=1;i<=n[0];i++)
		{
			for(j=1;j<=n[1];j++)
			{
				for(r=1;r<=min(n[0]+1-i,n[1]+1-j);r++)
				{
					if(a[0][i-1+r]!=a[1][j-1+r])
					{
						break;
					}
				}
				z=max(z,r-1);
			}
		}
		printf("%lld\n",n[0]+n[1]-z*2);
	}
}