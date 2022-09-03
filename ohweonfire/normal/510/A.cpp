#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(i&1)
			{
				if(j==m-1&&(i+3)%4==0)
					putchar('#');
				else if(j==0&&(i+1)%4==0)
					putchar('#');
				else
					putchar('.');
			}
			else
				putchar('#');
		puts("");
	}
	return 0;
}