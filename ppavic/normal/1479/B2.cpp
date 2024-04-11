#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

ll ccw(pt A, pt B, pt C) { return (ll)A.X * (B.Y - C.Y) + (ll)B.X * (C.Y - A.Y) + (ll)C.X * (A.Y - B.Y); }
int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
int mul(int A, int B) { return (ll)A * B % MOD; }
int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }

int T[2 * OFF], prop[2 * OFF], dp[N], A[N], off, n;

void update(int x, int kol){
	T[OFF + x] = max(T[OFF + x], kol);
	for(x = (x + OFF) / 2 ; x ; x /= 2)
		T[x] = max(T[2 * x], T[2 * x + 1]);
}

int query(int i, int a, int b, int x){
	if(a > x || b < x) return T[i];
	if(i >= OFF) return T[i] + 1;
	return max(query(2 * i, a, (a + b) / 2, x), query(2 * i + 1, (a + b) / 2 + 1, b, x));
}

int main(){
	for(int i = 0;i < 2 * OFF;i++) T[i] = -INF; 
	scanf("%d", &n);
	A[n + 1] = n + 1;
	for(int i = 1;i <= n;i++)
		scanf("%d", A + i);
	for(int i = 1;i <= n;i++){
		off += A[i] == A[i - 1];
		update(A[i - 1], dp[i - 1] - off);
		dp[i] = query(1, 0, OFF - 1, A[i + 1]) + off;
		//printf("dp[ %d ] = %d\n", i, dp[i]);
	}
	printf("%d\n", n - dp[n]);
	return 0;
}