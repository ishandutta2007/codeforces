#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,j;
	bool g=false;
	
	scanf("%lld",&n);
	string s[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		if(!g)
		{
			for(j=1;j<5;j++)
			{
				if(s[i][j]=='O'&&s[i][j-1]=='O')
				{
					s[i][j]='+';
					s[i][j-1]='+';
					g=true;
					break;
				}
			}
		}
	}
	if(g)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",s[i].c_str());
	}
}