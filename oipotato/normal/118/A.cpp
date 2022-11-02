#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s[110];
	scanf("%s",s+1);
	int len=strlen(s+1);
	rep(i,len)if('A'<=s[i]&&s[i]<='Z')s[i]=s[i]-'A'+'a';
	rep(i,len)if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y')printf(".%c",s[i]);puts("");
	return 0;
}