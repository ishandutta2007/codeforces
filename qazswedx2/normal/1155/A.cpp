#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,maxn,id;
char s[500005];
int main()
{
	scanf("%d%s",&n,s+1);
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(maxn<s[i]) maxn=s[i],id=i;
		else if(maxn>s[i])
		{
			printf("YES\n%d %d",id,i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}