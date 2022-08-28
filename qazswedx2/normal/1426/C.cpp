#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int nw=sqrt(n),ans=1e9;
		for(int i=max(1,nw-5);i<=min(nw+5,n);i++)
		{
			ans=min(ans,i+(n+i-1)/i-2);
		}
		printf("%d\n",ans);
	}
	return 0;
}