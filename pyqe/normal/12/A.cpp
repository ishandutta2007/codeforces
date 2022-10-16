#include <bits/stdc++.h>

using namespace std;

bitset<3> a[3];

int main()
{
	long long i,j;
	char ch;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='X';
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]!=a[2-i][2-j])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}