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

const int N = 1e5 + 500;
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

int dp[M], A[M], n, m, col[M], dp_col[M];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n * m;i++) dp[i] = 0, dp_col[i] = 0, col[i] = 0;
	int cur = 0, dobar_kol = 0;
	for(int i = 0;i < n * m;i++){
		char c; scanf(" %c", &c);
		A[i] = (c - '0'); cur += A[i];
		if(i >= m){
			cur -= A[i - m];
		}
		if(A[i] && (i < m || !col[i - m])){
			dobar_kol++;
		}
		if(A[i] || (i >= m && col[i - m]))
			col[i] = 1;
		dp_col[i] = dobar_kol;
		if(cur > 0){
			dp[i]++;
		}
	}
	for(int i = m;i < n * m;i++)
		dp[i] += dp[i - m];
	for(int i = 0;i < n * m;i++)
		printf("%d ", dp[i] + dp_col[i]);
	printf("\n"); 
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}