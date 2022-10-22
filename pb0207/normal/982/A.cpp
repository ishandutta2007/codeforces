#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n;

char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1)
	{
		puts(s[1]=='1'?"Yes":"No");
		return 0;
	}
	for(int i=1;i<n;i++)
		if(s[i]=='1'&&s[i+1]=='1')
		{
			puts("No");
			return 0;
		}
	for(int i=2;i<n;i++)
		if(s[i-1]=='0'&&s[i+1]=='0'&&s[i]=='0')
		{
			puts("No");
			return 0;
		}
	if(s[1]=='0'&&s[2]=='0')
	{
		puts("No");
		return 0;
	}
	if(s[n]=='0'&&s[n-1]=='0')
	{
		puts("No");
		return 0;
	}
	puts("Yes");
}