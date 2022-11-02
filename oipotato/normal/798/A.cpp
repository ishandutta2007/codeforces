#include<cstdio>
#include<cstring>
using namespace std;
char st[20];
int len,ans;
int main()
{
	scanf("%s",st);
	len=strlen(st);
	for(int i=0;i<len/2;i++)if(st[i]!=st[len-i-1])ans++;
	printf(ans==1||(ans==0&&len%2)?"YES":"NO");
	return 0;
}