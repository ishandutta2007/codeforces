#include<cstdio>
using namespace std;
int n,ans,d;
long long x;
char ch;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d\n",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%c%d\n",&ch,&d);
		if(ch=='+')x+=d;
		else x>=d?x-=d:ans++;
	}
	printf("%I64d %d",x,ans);
	return 0;
}