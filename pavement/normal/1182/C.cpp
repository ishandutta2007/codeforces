#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N;
string S[100005];
bool H[100005];
map<int, vector<int> > M;
map<ii, vector<int> > Y;
vector<ii> val, val2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		int V = 0;
		char lv;
		for (char c : S[i]) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') lv = c, V++;
		}
		if (Y[mp(V, lv - 'a')].size()) {
			H[i] = H[Y[mp(V, lv - 'a')].back()] = 1;
			val.eb(i, Y[mp(V, lv - 'a')].back());
			Y[mp(V, lv - 'a')].ppb();
		} else Y[mp(V, lv - 'a')].pb(i);
	}
	for (int i = 1; i <= N; i++) {
		if (H[i]) continue;
		int V = 0;
		char lv;
		for (char c : S[i]) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') lv = c, V++;
		}
		if (M[V].size()) {
			H[i] = H[M[V].back()] = 1;
			val2.eb(i, M[V].back());
			M[V].ppb();
		} else M[V].pb(i);
	}
	cout << min(val.size(), val2.size()) + (val.size() > val2.size() ? (val.size() - val2.size()) / 2 : 0) << '\n';
	for (int i = 0; i < min(val.size(), val2.size()); i++) {
		cout << S[val2[i].first] << ' ' << S[val[i].first] << '\n' << S[val2[i].second] << ' ' << S[val[i].second] << '\n';
	}
	if (val.size() > val2.size()) {
		if (val2.size() - val.size() & 1) val.ppb();
		for (int i = val2.size(); i < val.size(); i += 2) {
			cout << S[val[i].first] << ' ' << S[val[i + 1].first] << '\n' << S[val[i].second] << ' ' << S[val[i + 1].second] << '\n';
		}
	}
}