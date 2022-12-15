#include<cstdio>
#include<cstring>

char s[2000001];
int n;

int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	int i,j;
	for (i=0; i<n; i++)
		if (s[i]=='>') break;
	for (j=n-1; j>=0; j--)
		if (s[j]=='<') break;
	printf("%d",i+n-j-1);
	return 0;
}