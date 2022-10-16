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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

int n, A[N], L[N], R[N], dp[N], pmax[N]; 
int T[2 * OFF];

void update(int i, int x){
	T[OFF + i] = x;
	for(i = (i + OFF) / 2 ; i ; i /= 2)
		T[i] = max(T[2 * i], T[2 * i + 1]);
}

int query(int i, int a, int b, int lo, int hi){
	if(lo <= a && b <= hi) return T[i];
	if(a > hi || b < lo) return -INF;
	return max(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

int main(){
	for(int i = 0;i < 2 * OFF;i++) T[i] = -INF;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) L[i] = -1;
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		if(L[A[i]] == -1) L[A[i]] = i;
		R[A[i]] = i;
	}
	for(int i = 0;i < n;i++){
		dp[i] = (i ? dp[i - 1] : 0);
		if(R[A[i]] == i && L[A[i]] < i){
			dp[i] = max(dp[i], (L[A[i]] ? dp[L[A[i]] - 1] : 0) + i - L[A[i]] - 1);
			dp[i] = max(dp[i], query(1, 0, OFF - 1, L[A[i]], i) + i - 1);
		}
		update(i, dp[i] - i);
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}