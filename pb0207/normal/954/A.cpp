#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

char s[101];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='U'&&s[i+1]=='R')
			ans++,i++;
		else
		if(s[i]=='R'&&s[i+1]=='U')
			ans++,i++;
	}
	printf("%d",n-ans);
}