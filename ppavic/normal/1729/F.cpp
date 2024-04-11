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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 9; // 1e9 + 7

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

int P[N], n, w, m;
char s[N];
int prv[10], drg[10];

void solve(){
	memset(prv, -1, sizeof(prv));
	memset(drg, -1, sizeof(drg));
	scanf("%s", s); n = strlen(s);
	for(int i = 0;i < n;i++)
		P[i] = add((i ? P[i - 1] : 0), s[i] - '0');
	scanf("%d%d", &w, &m);
	for(int i = 0;i + w <= n;i++){
		int sm = sub(P[i + w - 1], (i ? P[i - 1] : 0));
		if(prv[sm] >= 0){
			if(drg[sm] < 0)
				drg[sm] = i;
		}
		else prv[sm] = i;
	}
	for(;m--;){
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		int x = sub(P[r - 1], (l - 1 ? P[l - 2] : 0));
		pii ans = (pii){INF, INF};
		for(int a = 0;a < 9;a++){
			for(int b = 0;b < 9;b++){
				if(prv[a] == -1 || prv[b] == -1) continue;
				if(a == b && drg[a] == -1) continue;
				if(add(mul(a, x), b) == k)
					ans = min(ans, {prv[a], a != b ? prv[b] : drg[b]});
			}
		}
		ans.X++, ans.Y++;
		if(ans >= (pii){INF, INF}) ans = {-1, -1};
		printf("%d %d\n", ans.X, ans.Y);
	}
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}