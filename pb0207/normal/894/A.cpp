#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n;

char s[1001];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')
					ans++;
	cout<<ans;
}