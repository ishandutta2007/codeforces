#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int n,ans=0,now=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		now-=x;now+=y;
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}