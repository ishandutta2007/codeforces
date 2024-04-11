#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],pos[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		LL ans=0;
		rep(i,n-1)ans+=1ll*(a[i+1]-a[i])*(1-1ll*i*(n-i));
		printf("%lld\n",ans);
	}
    return 0;
}