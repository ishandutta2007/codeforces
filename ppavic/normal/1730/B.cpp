#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

#define X first
#define Y second
#define PB push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < ll, ll > pll;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353; // 1e9 + 7
const ld EPS = 1e-10;

inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

vector < int > v;
int n, x[N], t[N]; 

bool check(ld ct, bool prnt = false){
	ld l = -INF, r = INF;
	for(int i = 0;i < n;i++){
		if(t[i] - EPS > ct) return false;
		l = max(l, x[i] - (ct - t[i]));
		r = min(r, x[i] + (ct - t[i]));
	}
	if(prnt)
		printf("%.10Lf\n", l);
	return l <= r;
}

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", x + i);
	for(int i = 0;i < n;i++)
		scanf("%d", t + i);
	ld lo = 0, hi = 1e10;
	for(int i = 0;i < 120;i++){
		ld mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	check(lo, true);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}