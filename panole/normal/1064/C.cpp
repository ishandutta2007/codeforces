#include<cstdio>
#include<cstring>

int n,t[26];
char s[500001];

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	memset(t,0,sizeof(t));
	for (int i=0; i<n; i++) t[s[i]-'a']++;
	for (int i=0; i<26; i++)
		for (int j=1; j<=t[i]; j++) putchar(i+'a');
	return 0;
}