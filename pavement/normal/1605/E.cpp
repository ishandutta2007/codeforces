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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, Q, ans, A[200005], B[200005], cnt[200005], ppos[200005], pneg[200005];
vector<int> pos, neg;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	B[1] = 0;
	cnt[1] = 1;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 1) pos.pb(B[i] - A[i]);
		else if (cnt[i] == -1) neg.pb(B[i] - A[i]);
		else ans += llabs(B[i] - A[i]);
		for (int j = i + i; j <= N; j += i) {
			A[j] += B[i] - A[i];
			cnt[j] -= cnt[i];
		}
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	for (int i = 0, prf = 0; i < pos.size(); i++) {
		prf += pos[i];
		ppos[i] = prf;
	}
	for (int i = 0, prf = 0; i < neg.size(); i++) {
		prf += neg[i];
		pneg[i] = prf;
	}
	cin >> Q;
	for (int X; Q--; ) {
		cin >> X;
		int cans = ans;
		int t = lower_bound(pos.begin(), pos.end(), -X) - pos.begin();
		if (t < pos.size()) cans += (ppos[pos.size() - 1] - (t ? ppos[t - 1] : 0ll)) + X * (pos.size() - t);
		if (t - 1 >= 0) cans += -(ppos[t - 1]) - t * X;
		t = lower_bound(neg.begin(), neg.end(), X) - neg.begin();
		if (t < neg.size()) cans += (pneg[neg.size() - 1] - (t ? pneg[t - 1] : 0ll)) - X * (neg.size() - t);
		if (t - 1 >= 0) cans += -(pneg[t - 1]) + t * X;
		cout << cans << '\n';
	}
}