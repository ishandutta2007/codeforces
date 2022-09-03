#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,s,x,y,ans=-1;
	scanf("%d%d",&n,&s);
	s*=100;
	while(n--)
	{
		scanf("%d%d",&x,&y);
		if(x*100+y<=s)
			ans=max(ans,(s-x*100-y)%100);
	}
	printf("%d\n",ans);
	return 0;
}