#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005],vis[1000005],cnt[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			vis[i]=cnt[i]=0;
		int nw=1,fr,ct=0;
		while(!vis[nw]) vis[nw]=1,cnt[nw]=ct,nw=nw-a[nw],ct++;
		fr=nw;
		printf("%d\n%d ",ct-cnt[fr],fr);
		nw=nw-a[nw];
		while(nw!=fr)
		{
			printf("%d ",nw);
			nw=nw-a[nw];
		}
		printf("\n");
	}
	return 0;
}