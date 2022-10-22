#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=3e5+1e1+7;

char s[N];

int a,b,c,n,ans;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		a=b=c=0;
		for(int j=i;j<=n;j++)
		{
			if(s[j]=='(')
				a++;
			else if(s[j]==')'||s[j]=='?')
				a--;
			if(s[j]=='?')
				c++;
			if(a<0)
			{
				if(c==0)
					break;
				else
					c--,a+=2;
			}
			if(a==0)
				ans++;
		}
	}
	printf("%d",ans);
}