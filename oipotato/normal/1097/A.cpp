#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
char s[10],t[10];
int main()
{
	scanf("%s",s);
	rep(i,5)
	{
		scanf("%s",t);
		if(t[0]==s[0]||t[1]==s[1]){puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}