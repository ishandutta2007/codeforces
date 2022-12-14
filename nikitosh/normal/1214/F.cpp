#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
#define FNAME ""

const int MAX_N = 2e5 + 10;
const ll INF = 1e18;

ll sum[MAX_N];
pair<ll, int> a[MAX_N], b[MAX_N];
int ans[MAX_N];
int n;
 
void addIn(int l, int r, int val) {
	sum[l] += val;
	sum[r] -= val;
}  
 
void add(int l, int r, int val) {
	if (l < 0)
		l += n, r += n;
	addIn(l, min(r, n), val);
	if (r > n)
		addIn(0, r - n, val);
} 
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
 
	int m;
	scanf("%d%d", &m, &n);
	forn (i, n)
		cin >> a[i].fs, a[i].sc = i;
	forn (i, n)
		cin >> b[i].fs, b[i].sc = i;
	sort(a, a + n);
	sort(b, b + n);
	
	forn (i, n) {
		ll x = a[i].fs;
		addIn(0, n, -x);
		int l = lower_bound(b, b + n, mp(x - m / 2, 0)) - b; 	
		int r = lower_bound(b, b + n, mp(x, 0)) - b; 	
		add(l - i, r - i, 2 * x);
		l = upper_bound(b, b + n, mp(x + m / 2, n)) - b; 	
		add(l - i, n - i, 2 * x + m);
	}
	
	forn (i, n) {
		ll y = b[i].fs;
		addIn(0, n, -y);
		int l = lower_bound(a, a + n, mp(y - m / 2, 0)) - a; 	
		int r = lower_bound(a, a + n, mp(y + 1, 0)) - a; 	
		add(i - r + 1, i - l + 1, 2 * y);
		l = upper_bound(a, a + n, mp(y + m / 2, n)) - a; 	
		add(i - n + 1, i - l + 1, 2 * y + m);
	}
	ll cur = 0;
	ll minn = INF;
	int ind = -1;
	forn (i, n) {
		cur += sum[i];
		if (minn > cur)
			minn = cur, ind = i;
	}
	cout << minn << "\n";	
	forn (i, n) 
		ans[a[i].sc] = b[(i + ind) % n].sc;
	forn (i, n)
		cout << ans[i] + 1 << " ";	
	return 0;
}