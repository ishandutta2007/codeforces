#include<cstdio>
using namespace std;
char ch,a[100010];
int len;
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	for(ch=getchar();'0'<=ch&&ch<='9';a[++len]=ch,ch=getchar());
	for(int i=1;i<=len;i++)printf("%c",a[i]);
	for(int i=len;i;i--)printf("%c",a[i]);
	return 0;
}