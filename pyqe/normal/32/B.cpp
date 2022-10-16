#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='.')
		{
			printf("0");
		}
		else
		{
			i++;
			if(s[i]=='.')
			{
				printf("1");
			}
			else
			{
				printf("2");
			}
		}
	}
	printf("\n");
}