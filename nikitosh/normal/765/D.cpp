#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;


const int N = 1e5 + 100;

vector<int> comps[N];
vector<int> res;
int num[N], f[N];

bool check(int x) {
	if (sz(comps[x]) == 0) {
		return true;
	}
	for (int t: comps[x]) {
		if (t == x) {
			res.pb(x);
			num[x] = sz(res);
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> f[i];
		comps[f[i]].pb(i + 1);
	}
	forab(i, 1, n + 1) {
		if (!check(i)) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << sz(res) << '\n';
	forn(i, n) {
		cout << num[f[i]] << ' ';
	}
	cout << '\n';
	forn(i, sz(res)) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}