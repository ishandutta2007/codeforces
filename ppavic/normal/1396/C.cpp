#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int n;
ll a[N], sol = 0, r1, r2, r3, d, bez[N], sa[N], suf[N];
ll dp[N][3];

int main(){
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for(int i = 0;i < n;i++){
		scanf("%lld", a + i);
		bez[i] = r1 * a[i] + r3;
		sa[i]  = min(r2, r1 * (a[i] + 1)) + r1;
	}
	suf[n - 1] = d + min(bez[n - 1], sa[n - 1] + d * 2);
	for(int i = n - 2;i >= 0;i--){
		suf[i] = min(sa[i], bez[i]) + d * 2 + suf[i + 1]; 		
	}
	ll ans = suf[0] - d;
	for(int i = 0;i < n;i++){
		if(!i){
			dp[i][0] = bez[i];
			dp[i][1] = sa[i] + d * 2;
			dp[i][2] = 1e17;
		}
		else{
			dp[i][0] = d + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + bez[i];
			dp[i][1] = d * 3 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + sa[i];
			dp[i][2] = d + dp[i - 1][1] + sa[i];
		}
		ll dom = min(dp[i][0], min(dp[i][1], dp[i][2]));
		ans = min(ans, dom + (i + 1 < n ? suf[i + 1] : 0));
	}
	printf("%lld\n", ans);
	return 0;
}