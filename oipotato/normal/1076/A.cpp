#include<cstdio>
using namespace std;
int n;
char s[200010];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<n;i++)
	if(s[i]>s[i+1])
	{
		for(int j=1;j<i;j++)putchar(s[j]);
		for(int j=i+1;j<=n;j++)putchar(s[j]);
		puts("");
		return 0;
	}
	for(int i=1;i<n;i++)putchar(s[i]);puts("");
	return 0;
}