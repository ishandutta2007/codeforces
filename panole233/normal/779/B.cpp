#include<cstdio>
#include<cstring>

char s[10001];
int x,len;

int main()
{
	scanf("%s",&s);
	scanf("%d",&x);
	len=strlen(s);
	int cnt=0;
	for (int i=0; i<len; i++)
		if (s[i]=='0') cnt++;
	if (cnt<x) {printf("%d",len-1); return 0;}
	cnt=0; int ans=0;
	for (int i=len-1; i>=0; i--)
		if (s[i]=='0') {cnt++; if (cnt==x) break;}
		else ans++;
	printf("%d",ans);
	return 0;
}