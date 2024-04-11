#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int n,m,mod;
ll ans=0;
map<int,int> mp;
int main()
{
	scanf("%d%d%d",&n,&mod,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int q=(1ll*x*x%mod*x%mod-m+mod)*x%mod;
		ans+=mp[q]++;
	}
	printf("%lld\n",ans);
	return 0;
}