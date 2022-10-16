#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j;
	string ky,s;
	
	cin>>ky;
	for(i=0;i<5;i++)
	{
		cin>>s;
		for(j=0;j<2;j++)
		{
			if(s[j]==ky[j])
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
}