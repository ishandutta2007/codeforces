#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int fl0=1,fl1=1;
		s[n+1]=s[1];
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='>') fl0=0;
			if(s[i]=='<') fl1=0;
		}
		if(fl0||fl1)
		{
			printf("%d\n",n);
			continue;
		}
		int ct=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='-'||s[i+1]=='-')
				ct++;
		printf("%d\n",ct);
	}
	return 0;
}