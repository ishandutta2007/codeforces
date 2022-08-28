#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100005],vis[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n+2;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		reverse(a+1,a+n+1);
		int ans=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&a[r+1]==a[l]) r++;
			if(r-l+1==1)
			{
				if(!vis[a[l]+1]) vis[a[l]+1]=1;
				else vis[a[l]]=1;
			}
			else vis[a[l]+1]=vis[a[l]]=1;
		}
		for(int i=1;i<=2*n+2;i++)
			ans+=vis[i];
		printf("%d\n",ans);
	}
	return 0;
}