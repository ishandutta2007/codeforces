#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	map<int, int> cnt;
	map<pii, int> cntP;
	forn (i, n) {
		int w, h;
		cin >> w >> h;
		if (w < h)
			swap(w, h);
		cnt[w]++;
		if (w != h)
			cnt[h]++;
		cntP[{w, h}]++;
	}
	ll ans = 0;
	for (auto np : cnt)
		ans += np.snd * 1ll * (np.snd - 1) / 2;
	for (auto np : cntP) {
		if (np.fst.fst != np.fst.snd)
			ans -= np.snd * 1ll * (np.snd - 1) / 2;
	}
	cout << ans << "\n";
	
	return 0;
}