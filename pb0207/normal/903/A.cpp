#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n; 

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		bool flag=false;
		for(int j=0;j<=x/3;j++)
			if((x-j*3)%7==0)
			{
				flag=1;
				break;
			}
		if(!flag)
			puts("NO");
		else
			puts("YES");
	}
}