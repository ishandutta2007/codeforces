#include<bits/stdc++.h>
using namespace std;

char s[150010];
int T,ans[150010],ansn,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ansn=0,scanf("%s",s+1),n=strlen(s+1);
		for (int i=1; i<=n-2; i++)
			if (s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			{
				if (i<n-2&&s[i+3]=='o') ans[++ansn]=i+1,i++;
				else ans[++ansn]=i+2,i+=2;
			} else
			if (s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e') ans[++ansn]=i+1,i++;
		printf("%d\n",ansn);
		for (int i=1; i<=ansn; i++) printf("%d ",ans[i]);puts("");
	}
	return 0;
}