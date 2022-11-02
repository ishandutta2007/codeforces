#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s[1100];
	scanf("%s",s);
	if('a'<=s[0]&&s[0]<='z')s[0]=s[0]-'a'+'A';
	printf("%s",s);
	return 0;
}