#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);

	int ans=0;
	if(a+1<=b&&a+2<=c)ans=max(ans,3*a+3);
	if(b-1<=a&&b+1<=c)ans=max(ans,3*b);
	if(c-2<=a&&c-1<=b)ans=max(ans,3*c-3);
	printf("%d\n",ans);
	return 0;
}