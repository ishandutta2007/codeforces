#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[101];

int main()
{
	scanf("%s",s);
	int pos;
	for(int i=strlen(s)-1;i>=0;i--)
		if(s[i]!='0')
		{
			pos=i;
			break;
		}
	for(int i=0;i<=pos;i++)
		if(s[i]!=s[pos-i])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
}