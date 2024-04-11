#include<cstdio>
#include<cstring>

char s[1001];
int ans;

int min(int a,int b) {return a<b?a:b;}

int main()
{
	scanf("%s",&s);
	ans=min(s[0]-'a','a'+26-s[0]);
	for (int i=1; i<strlen(s); i++)
		if (s[i]>s[i-1])
			ans+=min(s[i]-s[i-1],s[i-1]+26-s[i]);
		else 
			ans+=min(s[i-1]-s[i],s[i]+26-s[i-1]);
	printf("%d",ans);
	return 0;
}