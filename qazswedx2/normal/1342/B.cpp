#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int t,n;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		int fl=0,fl1=0;
		for(int i=0;i<n;i++)
			if(s[i]=='0') fl=1;
			else fl1=1;
		if(!fl||!fl1)
		{
			printf("%s\n",s);
			continue;
		}
		for(int i=1;i<=n;i++)
			printf("01");
		printf("\n");
	}
	return 0;
}