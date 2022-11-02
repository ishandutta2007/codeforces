#include <cstdio>
#include <algorithm>
using namespace std;
int n,num,ans;
char ch;
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		ch=getchar();
		if(ch==' ')
		{
			ans=max(ans,num);
			num=0;
		}
		else if('A'<=ch&&ch<='Z')
			num++;
	}
	ans=max(ans,num);
	printf("%d\n",ans);
	return 0;
}