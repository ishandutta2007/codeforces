#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,s,x,y,ans=-1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		ans=max(ans,x);
	}
	printf("%d\n",ans);
	return 0;
}