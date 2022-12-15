#include<cstdio>
#include<cstring>

const int mod=1000000007;

char s[1000001];
int l,ans,x;

int main()
{
	scanf("%s",&s);
	l=strlen(s); x=1;
	for (int i=l-1; i>=0; i--)
		if (s[i]=='a') ans=(ans+l-x-i)%mod,l=(2*l-x-i)%mod,x++;
	while (ans<0) ans+=mod;
	printf("%d",ans);
	return 0;
}