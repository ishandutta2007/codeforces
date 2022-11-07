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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, K, A[100005], ft[100005], ft2[100005];
map<int, int> cnt;

int ls(int x) { return x & -x; }

void add(int x) {
	//cout << "+ " << x << '\n';
	int ox = x;
	for (; x <= N; x += ls(x)) ft[x] += ox, ft2[x]++;
}

void del(int x) {
	//cout << "- " << x << '\n';
	int ox = x;
	for (; x <= N; x += ls(x)) ft[x] -= ox, ft2[x]--;
}

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

int qry2(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft2[p];
	return r;
}

int get(int k) {
	if (k == 0) return 0;
	if (qry(N) < k) return qry2(N);
	int lo = 0, hi = N, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (qry(mid) < k) ans = mid, lo = mid + 1;
		else hi = mid - 1;
	}
	assert(ans != -1);
	return qry2(ans) + (k - qry(ans)) / (ans + 1);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			cnt[A[i]]++;
		}
		int dist = cnt.size(), ans = LLONG_MAX;
		for (auto i : cnt)
			add(i.second);
		for (int mex = 0, holes = 0; mex <= N; mex++) {
			int op = 0;
			op = max(holes, cnt[mex]);
			if (cnt[mex]) del(cnt[mex]), dist--;
			if (op <= K) {
				int rop = K - cnt[mex];
				int tmp = get(rop);
				//cout << rop << ' ' << dist << " DIFF " << dist - tmp + mex << " MEX " << mex << '\n';
				int f1 = dist - tmp + mex;
				f1 = max(f1, 1ll);
				ans = min(ans, f1 - mex);
			}
			if (!cnt[mex]) holes++;
		}
		cout << ans << '\n';
		for (int i = 0; i <= N; i++)
			ft[i] = ft2[i] = 0;
		cnt.clear();
	}
}