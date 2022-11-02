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
	for(int i=1;i<=len;)
	{
		int j=i;
		for(;j<=len&&s[j]==s[i];j++);
		if(j-i>=7){puts("YES");return 0;}
		i=j;
	}
	puts("NO");
	return 0;
}