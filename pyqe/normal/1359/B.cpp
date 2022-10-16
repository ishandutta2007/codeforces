#include <bits/stdc++.h>

using namespace std;

long long n,m,a[2];

int main()
{
	long long t,rr,i,j,k,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,a,a+1);
		a[1]=min(a[1],a[0]*2);
		z=0;
		for(i=0;i<n;i++)
		{
			cin>>s;
			c=0;
			for(j=0;j<=m;j++)
			{
				k=1;
				if(j<m)
				{
					k=s[j]=='*';
				}
				if(!k)
				{
					c++;
				}
				else
				{
					z+=c%2*a[0]+c/2*a[1];
					c=0;
				}
			}
		}
		printf("%lld\n",z);
	}
}