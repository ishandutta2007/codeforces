#include <cstdio>
#include <cstring>
#include <cstdlib>
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
typedef vector < int > vi;

const int N = 1e6 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

vector < int > v[N];

int n, m, g, A[N];
ll dp[N][2];

ll do_dp(vector < int > &v){
	dp[0][0] = v[0]; dp[0][1] = -(ll)1e18;
	for(int i = 1;i < (int)v.size();i++){
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) + v[i];
		dp[i][1] = max(dp[i - 1][0] - 2 * v[i - 1], dp[i - 1][1] + 2 * v[i - 1]) - v[i];
	}
	return max(dp[(int)v.size() - 1][0], dp[(int)v.size() - 1][1]);
}


void solve(){
	scanf("%d%d", &n, &m); g = 0;
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	for(int j = 0;j < m;j++){
		int x; scanf("%d", &x);
		g = __gcd(x, g);
	}
	for(int i = 0;i < n;i++)
		v[i % g].PB(A[i]);
	ll ans0 = 0, ans1 = 0;
	for(int i = 0;i < g;i++){
		ans0 += do_dp(v[i]);
		v[i][0] *= -1;
		ans1 += do_dp(v[i]);
		v[i].clear();
	}
	printf("%lld\n", max(ans0, ans1));
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}