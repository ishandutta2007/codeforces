#include<bits/stdc++.h>
using namespace std;

int n;

char s[101],t[]="abacaba",ans[101];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int tot=0;
		bool fd=0;
		for(int i=1;i<=n-7+1;i++)
		{
			memset(ans,0,sizeof(ans));
			int ok=1;
			for(int j=i;j<=i+7-1;j++)
				if(s[j]=='?')
					ans[j]=t[j-i];
				else if(s[j]==t[j-i])
					ans[j]=s[j];
				else
					ok=0;
			if(!ok)
				continue;
			for(int j=1;j<i;j++)
				ans[j]=s[j]=='?'?'z':s[j];
			for(int j=i+7;j<=n;j++)
				ans[j]=s[j]=='?'?'z':s[j];
			int sum=0;
			for(int j=1;j<=n-7+1;j++)
			{
				int ok=1;
				for(int k=j;k<=j+7-1;k++)
					ok&=ans[k]==t[k-j];
				sum+=ok;
			}
			if(sum==1)
			{
				fd=1;
				puts("Yes");
				puts(ans+1);
				break;
			}
		} 
		if(!fd)
			puts("No");
	}
}