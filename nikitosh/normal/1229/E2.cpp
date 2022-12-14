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

const int MAX_N = 10, MOD = 1e9 + 7;

int a[MAX_N][MAX_N];

inline int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

inline int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + MOD : a;
}

inline int mul(int a, int b) {
	return (a * 1ll * b) % MOD;
}

inline int power(int a, int n) {
	if (!n)
		return 1;
	int b = power(a, n / 2);
	b = mul(b, b);
	return n & 1 ? mul(b, a) : b;
}

inline int rev(int a) {
	return power(a, MOD - 2);
}

inline int divv(int a, int b) {
	return mul(a, rev(b));
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		forn (j, n) {
			scanf("%d", &a[i][j]);
			a[i][j] = divv(a[i][j], 100);
		}
	vector<pair<vector<char>, int>> sets, newSets;
	vector<char> newSet;
	sets.pb(mp(vector<char>{0}, 1));
	forn (g, n) {
		newSets.clear();
		forn (mask, (1 << n)) {
			int value = 1;
			forn (j, n)
				if (mask & (1 << j))
					value = mul(value, a[j][g]);
				else
					value = mul(value, sub(1, a[j][g]));
			for (auto& np : sets) {
				newSet.clear();
				for (int mask2 : np.fs) {
					int possible = ~mask2 & mask;
					while (possible) {
						int pos = possible & (-possible);
						newSet.pb(mask2 | pos);
						possible ^= pos;
					}
				}
				if (!sz(newSet))
					continue;
				sort(all(newSet));
				newSet.resize(unique(all(newSet)) - newSet.begin());
				newSets.pb(mp(newSet, mul(np.sc, value)));
			}
		}
		sort(all(newSets));
		sets.clear();
		int i = 0;
		while (i < sz(newSets)) {
			int j = i;
			int sumVal = 0;
			while (j < sz(newSets) && newSets[j].fs == newSets[i].fs)
				sumVal = add(sumVal, newSets[j].sc), j++; 
			sets.pb(mp(newSets[i].fs, sumVal));
			i = j;
		}
	}
	int res = 0;
	for (auto& np : sets)
		res = add(res, np.sc);
	cout << res << "\n";
	return 0;
}