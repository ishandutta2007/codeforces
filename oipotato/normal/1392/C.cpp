#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int inf=(int)1e9+10;
long long a[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		rep(i,n)scanf("%lld",&a[i]);
		long long ans=0;
		rep(i,n)
		{
			if(a[i]+ans<a[i-1])ans=a[i-1]-a[i];
			a[i]+=ans;
		}
		printf("%lld\n",ans);

	}
    return 0;
}