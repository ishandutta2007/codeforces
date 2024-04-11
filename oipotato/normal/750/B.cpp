#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
char s[20];
int now,n;
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		int x;
		scanf("%d%s",&x,s);
		if(s[0]=='N')now-=x;
		else if(s[0]=='S')now+=x;
		else if(s[0]=='E'||s[0]=='W')if(now==0||now==20000){puts("NO");return 0;}
		if(now<0||now>20000){puts("NO");return 0;}
	}
	puts(now==0?"YES":"NO");
	return 0;
}