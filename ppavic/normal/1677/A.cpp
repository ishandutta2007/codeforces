#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 5050;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << 18);
const int MOD = 998244353;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

int n, L[N][N], R[N][N], p[N];

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", p + i), p[i]--;			
	}
	for(int i = 0;i <= n;i++)
		for(int j = 0;j < n;j++)
			L[i][j] = 0, R[i][j] = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			L[i][j] = (i ? L[i - 1][j] : 0) + (p[i] <= j);
			R[n - i - 1][j] = R[n - i][j] + (p[n - i - 1] <= j);
		}
	}
	ll ans = 0;
	for(int b = 1;b < n;b++){
		for(int c = b + 1;c + 1 < n;c++){
			ans += (ll)L[b - 1][p[c]] * R[c + 1][p[b]];
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}