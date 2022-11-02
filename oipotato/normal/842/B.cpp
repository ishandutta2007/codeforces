#include <cstdio>
using namespace std;
int R,d,x,y,r,ans,n;
int main()
{
	scanf("%d%d",&R,&d);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&r);
		if(r<=R&&(R-d+r)*(R-d+r)<=x*x+y*y&&x*x+y*y<=(R-r)*(R-r))
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}