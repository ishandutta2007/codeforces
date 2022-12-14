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

const int MAX_N = 7005;

ll a[MAX_N];
int b[MAX_N], cnt[MAX_N], was[MAX_N];
bool c[MAX_N][MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		cin >> b[i];
	}
	const ll max = (1ll << 60) - 1;
	forn (i, n)
		forn (j, n) 
			if (i != j && (a[i] & (a[j] ^ max)))
				c[i][j] = 1, cnt[i]++;
	ll ans = 0;
	int rest = n;
	while (1) {
		bool deleted = 0;
		forn (i, n)
			if (!was[i] && cnt[i] == rest - 1) {
				was[i] = 1;
				forn (j, n)
					if (c[j][i])
						cnt[j]--;
				rest--;
				deleted = 1;
			}
		if (!deleted)
			break;
	}
	forn (i, n)
		if (!was[i])
			ans += b[i];
	cout << ans << "\n";
	return 0;
}