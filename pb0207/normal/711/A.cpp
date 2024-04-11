#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[1001][101];

int n;

int main()
{
	scanf("%d",&n);
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		if(s[i][0]==s[i][1]&&s[i][1]=='O'&&!flag)
			s[i][0]=s[i][1]='+',flag=true;
		if(s[i][3]==s[i][4]&&s[i][4]=='O'&&!flag)
			s[i][3]=s[i][4]='+',flag=true;
	}
	if(!flag)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%s\n",s[i]);
	}
}