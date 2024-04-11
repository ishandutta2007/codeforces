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

const int N = 5e3 + 50;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

char s[N];
int n, a, b, c, d;

void solve(){
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for(int i = 0;i < 16;i++){
		int aa = a, bb = b, cc = c, dd = d;
		if(i & 1) aa--, bb--;
		if(i & 2) bb--, cc--;
		if(i & 4) cc--, dd--;
		if(i & 8) dd--, aa--;
		if(min(min(aa, bb), min(cc, dd)) < 0) continue;
		if(max(max(aa, bb), max(cc, dd)) > n - 2) continue;
		printf("yes\n"); return;
	}
	printf("no\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}