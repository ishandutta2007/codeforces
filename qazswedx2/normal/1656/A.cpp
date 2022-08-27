#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int mx=-1,mxid=-1,mn=1e9+100,mnid=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>mx) mx=a[i],mxid=i;
			if(a[i]<mn) mn=a[i],mnid=i;
		}
		printf("%d %d\n",mxid,mnid);
	}
	return 0;
}