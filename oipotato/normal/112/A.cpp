#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s1[110],s2[110];
	scanf("%s%s",s1+1,s2+1);
	int len=strlen(s1+1);
	rep(i,len)if('A'<=s1[i]&&s1[i]<='Z')s1[i]=s1[i]-'A'+'a';
	rep(i,len)if('A'<=s2[i]&&s2[i]<='Z')s2[i]=s2[i]-'A'+'a';
	rep(i,len)if(s1[i]!=s2[i]){puts(s1[i]<s2[i]?"-1":"1");return 0;}
	puts("0");
	return 0;
}