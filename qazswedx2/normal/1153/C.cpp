#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt=0,nw=0;
char s[1000005];
int main()
{
	scanf("%d%s",&n,s+1);
	if(s[1]==')'||s[n]=='('||n%2==1)
	{
		printf(":(");
		return 0;
	}
	s[1]='(';
	s[n]=')';
	for(int i=2;i<n;i++)
		if(s[i]=='(') cnt++;
	cnt=(n-2)/2-cnt;
	if(cnt<0)
	{
		printf(":(");
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		if(s[i]=='?')
		{
			if(cnt>0) s[i]='(',cnt--;
			else s[i]=')';
		}
		if(s[i]=='(') nw++;
		else if(s[i]==')')
		{
			nw--;
			if(nw<0)
			{
				printf(":(");
				return 0;
			}
		}
	}
	if(nw!=0)
	{
		printf(":(");
		return 0;
	}
	else
	{
		printf("%s",s+1);
	}
	return 0;
}