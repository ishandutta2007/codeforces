#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,p[1000005],a[1000005][2],b[1000005],mx[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=2;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i][0],&a[i][1]);
		for(int i=1;i<=n;i++)
			mx[i]=0;
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			if(mx[i]<a[i][0]) b[i]=a[i][1],ans++;
			else b[i]=mx[i];
			//printf("i=%d,mx=%d,b=%d\n",i,mx[i],b[i]);
			if(i==1) break;
			int fa=p[i];
			mx[fa]=min(a[fa][1],mx[fa]+b[i]);
		}
		printf("%d\n",ans);
	}
}