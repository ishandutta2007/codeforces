#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1005],ans=2e9+100;
int solve(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=x/a[i];
		x%=a[i];
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int ans1=1,ans2=0,x=a[i-1]-1;
			for(int k=1;k<=j;k++)
			{
				ans1+=x/a[k];
				x%=a[k];
			}
			x=a[i-1]-1-x;
			ans2=solve(x+a[j]);
			if(ans1<ans2) ans=min(ans,x+a[j]);
		}
	if(ans>2e9) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}