#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1069> a[1069];

int main()
{
	long long t,rr,i,j;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=n;j++)
			{
				a[i][j]=s[j-1]-'0';
			}
		}
		for(i=1;i<n&&i;i++)
		{
			for(j=1;j<n;j++)
			{
				if(a[i][j]&&!a[i+1][j]&&!a[i][j+1])
				{
					i=-1;
					break;
				}
			}
		}
		if(!i)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}