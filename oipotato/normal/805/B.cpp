#include<cstdio>
using namespace std;
char ch[200010];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i+=4)
	{
		ch[i]=ch[i+1]='a';
		ch[i+2]=ch[i+3]='b';
	}
	for(int i=1;i<=n;i++)putchar(ch[i]);
	return 0;
}