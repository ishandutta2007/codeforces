#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	int n,a[110],k;
	scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d",&a[i]);
	int ans=0;
	rep(i,n)if(a[i]&&a[i]>=a[k])ans++;
	printf("%d\n",ans);
	return 0;
}