#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int main() 
{
	int n,h,b;
	h=0;
	b=0;
	cin>>n;
	char a[n][n];
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='C')
			{
			    b++;
		    }
		}
		h+=(b*(b-1)/2);
		b=0;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if(a[j][i]=='C')
			    b++;
		}
		h+=(b*(b-1)/2);
		b=0;
	}
    cout<<h;
	return 0;
}