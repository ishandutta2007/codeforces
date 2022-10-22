#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

char s[5][N];

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	puts("YES");
	if(k%2==0)
	{
		for(int i=1;i<=k/2;i++)
			s[2][i+1]=s[3][i+1]='#';
	}
	else
	{
		if(k<=n-2)
		{
			s[2][n/2+1]='#';
			int l=n/2,r=n/2+2;
			k--;
			for(;k!=0;k-=2,l--,r++)
				s[2][l]=s[2][r]='#';
		}
		else
		{
			for(int i=2;i<=n-1;i++)
				s[2][i]='#';
			k-=n-2;
			int l=2,r=n-1;
			for(;k!=0;k-=2,l++,r--)
				s[3][l]=s[3][r]='#';
		}
	}
	for(int i=1;i<=4;i++,puts(""))
		for(int j=1;j<=n;j++)
			putchar(s[i][j]=='#'?s[i][j]:'.');
}