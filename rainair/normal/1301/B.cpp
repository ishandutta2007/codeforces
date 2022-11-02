#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
int a[MAXN];
std::vector<int> S;

signed main(){
	int T;scanf("%lld",&T);
	while(T--){
		int n;scanf("%lld",&n);
		FOR(i,1,n) scanf("%lld",a+i);
		int mx=-1e18,mn = 1e18,cnt = 0;S.clear();
		FOR(i,1,n){
			if(a[i] == -1){
				S.pb(i);
				if(a[i-1] != -1 && i != 1) mx = std::max(mx,a[i-1]),mn = std::min(mn,a[i-1]),++cnt;
				if(a[i+1] != -1 && i != n) mx = std::max(mx,a[i+1]),mn = std::min(mn,a[i+1]),++cnt;
			}
		}
		if(!cnt){
			printf("%lld %lld\n",0ll,0ll);continue;
		}
		// DEBUG(mn);DEBUG(mn);
		int mid = (mx+mn)>>1;
		int pos = -1,ans = 1e18;
		FOR(k,std::max(0ll,mid-2),mid+2){
			int t = 0;
			for(auto x:S) a[x] = k;
			FOR(i,2,n){
				t = std::max(t,std::llabs(a[i]-a[i-1]));
			}
			if(t < ans){
				ans = t;pos = k;
			}
		}
		printf("%lld %lld\n",ans,pos);
	}
	return 0;
}