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
const int MOD=(int)1e9+7;
LL gcd(LL a,LL b){return !b?a:gcd(b,a%b);}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		LL n,lcm=1;scanf("%lld",&n);
		int ans=0;
		for(int i=2;;i++)
		{
			int tmp=n/lcm%MOD;
			LL z=gcd(lcm,1ll*i);
			lcm/=z;
			if(n/i<lcm){ans=(ans+1ll*i*tmp)%MOD;break;}
			lcm*=i;
			tmp=(tmp-n/lcm%MOD+MOD)%MOD;
			ans=(ans+1ll*i*tmp)%MOD;
		}
		printf("%d\n",ans);
	}
    return 0;
}