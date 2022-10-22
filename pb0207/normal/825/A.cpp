#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,ans;

char s[101];

int main()
{
	cin>>n;
	scanf("%s",s);
	int now=1,bb=0;
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]=='1')
		{
			bb++;
		}
		else
		if(s[i]=='0')
		{
			ans+=bb*now;
			bb=0;
			now*=10;
		}
	}
	if(bb)
		ans+=bb*now;
	cout<<ans;
}