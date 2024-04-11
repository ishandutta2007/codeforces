#include "bits/extc++.h"

using namespace std;

template<class T, class U = less<T>>
using rt = __gnu_pbds::tree<T, __gnu_pbds::null_type, U, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<class T, class U>
void sep(T &out, const string &s, const U &u) {
	out << u;
}

template<class T, class Head, class ...Tail>
void sep(T &out, const string &s, const Head &h, const Tail &...t) {
	out << h << s;
	sep(out, s, t...);
}

#ifdef DEBUG
#define dbg(...)                                                      \
cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]" << ": ";       \
sep(cerr, " | ", __VA_ARGS__);                                        \
cerr << endl
#else
#define cerr if(false) cerr
#define dbg(...) cerr
#endif

//imagine a language where int = long
#define long int64_t

//typing too hard
#define endl "\n"

#define sz(x) int((x).size())

const long mod = 1e9+7;

const int maxn = 1e6;
long fact[maxn];

void pcomp() {
	fact[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
}

void solve() {
	pcomp();
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> occur[m];
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		map<int, int> cnt;
		for(int j = 0; j < x; j++) {
			int y;
			cin >> y;
			y--;
			cnt[y]++;
		}
		for(auto &[k, v]: cnt) {
			occur[k].emplace_back(i, v);
		}
	}
	map<vector<pair<int, int>>, int> acnt;
	for(int i = 0; i < m; i++) {
		acnt[occur[i]]++;
	}
	long ans = 1;
	for(auto &[k, v]: acnt) {
		dbg(v);
		ans = (ans * fact[v]) % mod;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::failbit);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t = 1;
//	cin >> t;
	for(int _ = 1; _ <= t; _++) {
		dbg(_);
//		cout << "Case #" << _ << ": ";
		solve();
	}
}