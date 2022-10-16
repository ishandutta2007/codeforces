#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,j;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		for(i=0;i<6;i++)
		{
			for(j=i+1;j<6;j++)
			{
				if(s[j]==s[i]-'A'+'a')
				{
					break;
				}
			}
			if(j<6)
			{
				break;
			}
		}
		if(i>=6)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}