#include<bits/stdc++.h>
using namespace std;

int T;

char s[111];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n>=3)
			printf("%c\n",*min_element(s+1,s+n+1));
		else
			printf("%c\n",s[2]);
	}
}