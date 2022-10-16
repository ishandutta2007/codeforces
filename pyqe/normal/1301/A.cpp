#include <bits/stdc++.h>

using namespace std;

long long n,a[3][100069];

int main()
{
	long long t,rr,i,j;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			cin>>s;
			n=s.length();
			for(j=1;j<=n;j++)
			{
				a[i][j]=s[j-1]-'a';
			}
		}
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[0][i]!=a[2][i]&&a[1][i]!=a[2][i])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}