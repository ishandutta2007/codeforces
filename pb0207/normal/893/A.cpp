#include<cstdio>
#include<iostream>
using namespace std;

int a[4];

int n,x;

int main()
{
	cin>>n;
	a[1]=a[2]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(a[x]!=1)
		{
			puts("NO");
			return 0;
		}
		for(int j=1;j<=3;j++)
		{
			if(a[j]==1&&j!=x)
				a[j]=0;
			else
			if(a[j]==0&&j!=x)
				a[j]=1;
		}
	}
	puts("YES");
}