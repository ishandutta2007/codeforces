#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],nxt[100005],vis[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(vis,0x3f,sizeof(vis));
	for(int i=n;i;i--)
	{
		nxt[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	int x=0,y=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[x]==a[i]) x=i;
		else if(a[y]==a[i]) y=i;
		else
		{
			ans++;
			if(vis[a[x]]>vis[a[y]]) x=i;
			else y=i;
		}
		vis[a[i]]=nxt[i];
	}
	printf("%d\n",ans);
	return 0;
}