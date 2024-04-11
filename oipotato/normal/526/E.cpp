#include <cstdio>
#include <algorithm>
using namespace std;
long long s[2000010],b;
int a[1000010],nxt[2000010],n,q,ans;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		s[i+n]=s[i+n-1]+a[i];
	for(int i=1;i<=q;i++)
	{
		scanf("%I64d",&b);
		int r=1,minid=-1;
		for(int j=1;j<=2*n;j++)
		{
			for(;r<2*n&&s[r+1]-s[j-1]<=b;r++);
			nxt[j]=r;
			if(nxt[j]>nxt[j-1]&&j>1&&j<=n+1&&(minid==-1||nxt[minid]-minid+1>nxt[j]-j+1))
				minid=j;
		}
		if(minid==n+1)
			minid=1;
		ans=n;
		if(minid==-1)
		{
			puts("1");
			continue;
		}
		for(int j=minid;j<=nxt[minid];j++)
		{
			int p=j>n?j-n:j,st=j>n?j-n:j,tans=0;
			for(;p-st<n;p=nxt[p]+1)
				tans++;
			ans=min(ans,tans);
		}
		printf("%d\n",ans);
	}
	return 0;
}