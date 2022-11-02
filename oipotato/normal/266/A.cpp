#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s[1100];
	int n,ans=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;)
	{
		int j=i;
		for(;j<=n&&s[j]==s[i];j++);
		ans+=j-i-1;
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}