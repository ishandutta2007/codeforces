#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,j,k,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=0;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				k=s[j-1]=='R';
				z+=((i==n&&!k)||(j==m&&k))&&!(i==n&&j==m);
			}
		}
		printf("%lld\n",z);
	}
}