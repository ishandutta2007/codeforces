#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,len;
char s[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		int fl=0,fl2=0,sum=0;
		for(int j=1;j<=len;j++)
		{
			sum+=s[j]-'0';
			if(!fl&&s[j]=='0') fl=1;
			else if((s[j]-'0')%2==0) fl2=1;
		}
		if(fl&&fl2&&sum%3==0) printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}