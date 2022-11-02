#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n)
	{
		char s[210];
		scanf("%s",s);
		if(strlen(s)>10)
		{
			printf("%c%d%c\n",s[0],strlen(s)-2,s[strlen(s)-1]);
		}
		else printf("%s\n",s);
	}
	return 0;
}