#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, D, A[100005];
ld lA[100005], mem[100005][25];
bool rdy[100005][25], nxt[100005][25];

ld dp(int n, int d) {
	if (n == N + 1) {
		if (d == D) return -1.;
		else return -2.;
	}
	if (rdy[n][d + 1]) return mem[n][d + 1];
	rdy[n][d + 1] = 1;
	mem[n][d + 1] = -2.;
	ld fst = dp(n + 1, (d == -1 ? A[n] : d * A[n]) % 10);
	vector<pair<ld, bool> > tmp;
	if (fst == -1.) tmp.eb(lA[n], 0);
	else if (fst != -2.) tmp.eb(fst + lA[n], 0);
	ld snd = dp(n + 1, d);
	if (snd == -1.) tmp.eb(0., 1);
	else if (snd != -2.) tmp.eb(snd, 1);
	if (tmp.empty()) {
		mem[n][d + 1] = -2.;
		return mem[n][d + 1];
	}
	sort(tmp.begin(), tmp.end(), greater<pair<ld, bool> >());
	nxt[n][d + 1] = tmp[0].second;
	return mem[n][d + 1] = tmp[0].first;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> D;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		lA[i] = (ld)log(A[i]) / log(1000);
	}
	ld ret = dp(1, -1);
	if (ret == -2.) return cout << "-1\n", 0;
	vector<int> out;
	for (int cn = 1, cd = -1; cn <= N; cn++)
		if (!nxt[cn][cd + 1]) out.pb(A[cn]), cd = (cd == -1 ? A[cn] : cd * A[cn]) % 10;
	assert(!out.empty());
	cout << out.size() << '\n';
	for (int i : out) cout << i << ' ';
	cout << '\n';
}