#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const ll LINF = (ll)1e18;
const int OOFF = (1 << 20);


int n,m, A[N], B[N], OFF = 1;

ll propA[2 * OOFF], propB[2 * OOFF];

inline void refresh(int x){
	if(propA[x] == 0 && propB[x] == -LINF) return;
	if(x < OFF){
		propB[2 * x] = max(propB[2 * x], propB[x] - propA[2 * x]);
		propB[2 * x + 1] = max(propB[2 * x + 1], propB[x] - propA[2 * x + 1]);
		propA[2 * x] += propA[x]; propA[2 * x + 1] += propA[x];
	}
	propA[x] = 0; propB[x] = -LINF;
}

void update(int i, int a, int b, int lo, int hi, int nw){
	if(lo <= a && b <= hi){
		propA[i] += nw; return;
	}
	if(a > hi || b < lo) return;
	refresh(i);
	update(2 * i, a, (a + b) / 2, lo, hi, nw);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, nw);
}

vector < int > saz;

int loga[N], loga_siz;

void add(int x){
	for(;x < loga_siz; x += x & -x) loga[x]++;
}

int query(int x){
	int ret = 0;
	for(; x ; x -= x & -x) ret += loga[x];
	return ret;
}

void solve(){
	scanf("%d%d", &n, &m); OFF = 1;
	while(OFF <= m) OFF <<= 1;
	for(int i = 0;i < n;i++) scanf("%d", A + i);
	for(int i = 0;i < m;i++) scanf("%d", B + i);
	
	for(int i = 0;i < 2 * OFF;i++) propA[i] = 0, propB[i] = -LINF;
	sort(B, B + m);
	
	for(int i = 0;i < n;i++){
		int dol = lower_bound(B, B + m, A[i]) - B;
		int gor = upper_bound(B, B + m, A[i]) - B;
		update(1, 0, OFF - 1, gor + 1, m, -1);
		update(1, 0, OFF - 1, 0, 0, dol);
		update(1, 0, OFF - 1, 1, dol, 1);
		propB[1] = max(propB[1], -propA[1]);
	}
	for(int i = 1;i < OFF;i++)
		refresh(i);
	ll sol = propA[OFF] + max(0LL, propB[OFF]);
	for(int i = 1;i < OFF;i++) sol -= propA[OFF + i] + max(0LL, propB[OFF + i]);
	saz.clear();
	for(int i = 0;i < n;i++) saz.PB(A[i]);
	sort(saz.begin(), saz.end());
	saz.erase(unique(saz.begin(), saz.end()), saz.end());
	for(int i = 0;i < n;i++)
		A[i] = lower_bound(saz.begin(), saz.end(), A[i]) - saz.begin() + 1;
	loga_siz = n + 10;
	for(int i = 0;i < loga_siz;i++) loga[i] = 0;
	for(int i = 0;i < n;i++){
		sol += i - query(A[i]); add(A[i]);
	}
	printf("%lld\n", sol);
	
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}