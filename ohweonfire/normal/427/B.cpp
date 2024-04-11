#include <stdio.h>
using namespace std;
int main()
{
 	int n,t,c,cnt=0,ans=0,x;
 	scanf("%d%d%d",&n,&t,&c);
 	while(n--)
 	{
	 		  scanf("%d",&x);
	 		  if(x<=t)cnt++;else cnt=0;
	 		  if(cnt>=c)ans++;
	}
	printf("%d\n",ans);
	return 0;
}