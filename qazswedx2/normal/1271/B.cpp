#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
int n,ctw,ctb,tans[100005],tt;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='W')
			ctw++;
		else ctb++;
	if(ctw%2&&ctb%2)
	{
		printf("-1");
		return 0;
	}
	if(ctw%2==0)
	{
		for(int i=1;i<n;i++)
			if(s[i]=='W')
			{
				tans[++tt]=i;
				if(s[i+1]=='B') s[i+1]='W';
				else s[i+1]='B';
			}
	}
	else
	{
		for(int i=1;i<n;i++)
			if(s[i]=='B')
			{
				tans[++tt]=i;
				if(s[i+1]=='B') s[i+1]='W';
				else s[i+1]='B';
			}
	}
	printf("%d\n",tt);
	for(int i=1;i<=tt;i++)
		printf("%d ",tans[i]);
	return 0;
}