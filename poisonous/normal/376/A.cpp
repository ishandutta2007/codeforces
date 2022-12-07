#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char s[1000100];
int  main()
{
	scanf("%s",s);
	int n,m,t;
	long long ans=0;
	for(n=0;n<strlen(s);n++)
		if(s[n]=='^')
			m=n;
	for(n=0;n<strlen(s);n++)
		if(s[n]>='0'&&s[n]<='9')
			ans+=(s[n]-'0')*(n-m);
	if(ans>0)
		cout<<"right";
	else
		if(ans<0)
			cout<<"left";
		else
			cout<<"balance";
		
}