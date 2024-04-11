#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[51];

int ans;

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			bool flag=true;
			for(int l=i,r=j;l<=r;l++,r--)
				flag&=(s[l]==s[r]);
			if(!flag)
				ans=max(ans,j-i+1);
		}
	printf("%d",ans);
}