#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],b[100005],vis[100005],mx=-1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[i-1]) b[i-1]=1;
	}
	for(int l=1,r;l<=n-1;l=r+1)
	{
		r=l;
		while(r<n-1&&b[r+1]==b[l]) r++;
		int len=r-l+1;
		vis[len]++;
		mx=max(mx,len);
	}
	int ans=0;
	for(int i=2;i<=n-1;i++)
		if(a[i]>a[i-1]&&a[i]>a[i+1])
		{
			int l=i,r=i;
			while(l>1&&a[l-1]<a[l]) l--;
			while(r<n&&a[r+1]<a[r]) r++;
			if(r-i==i-l&&vis[i-l]==2&&mx==i-l&&(i-l)%2==0)
				ans=1;
		}
	printf("%d\n",ans);
	return 0;
}