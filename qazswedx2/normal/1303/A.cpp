#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ft=0,lt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
				lt=i;
		for(int i=n;i;i--)
			if(s[i]=='1')
				ft=i;
		if(!ft)
		{
			printf("0\n");
			continue;
		}
		int ct=0;
		for(int i=ft;i<=lt;i++)
			if(s[i]=='0') ct++;
		printf("%d\n",ct);
	}
	return 0;
}