#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mod,a[1000005];
inline int getans(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n>mod)
	{
		printf("0\n");
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=1ll*ans*getans(a[i]-a[j])%mod;
	printf("%d\n",ans);
	return 0;
}