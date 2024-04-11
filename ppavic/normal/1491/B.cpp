#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int n, A[N], u, v;

void solve(){
	scanf("%d%d%d", &n, &v, &u);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	int mks = 0;
	for(int i = 0;i + 1 < n;i++)
		mks = max(mks, abs(A[i] - A[i + 1]));
	if(mks == 0)
		printf("%d\n", u + min(u, v));
	else if(mks == 1)
		printf("%d\n", min(u, v));
	else
		printf("0\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}