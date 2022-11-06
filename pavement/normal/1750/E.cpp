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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, A[400005], ft1[400005], ft2[400005], lft[200005], rig[200005];
char S[200005];
stack<ii> st;

int ls(int x) { return x & -x; } 

int qry(int p, int ft[]) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p, int v, int ft[]) {
	for (; p <= 2 * N + 1; p += ls(p)) ft[p] += v;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
			if (S[i] == '(') A[i] = 1;
			else A[i] = -1;
			A[i] += A[i - 1];
		}
		for (int i = 1; i <= 2 * N + 1; i++) {
			ft1[i] = ft2[i] = 0;
		}
		upd(N + 1, 1, ft1);
		upd(N + 1, 0, ft1);
		for (int i = 1; i <= N; i++) {
			// sum of (A[i] - A[j]) for all A[i] - A[j] >= 0 and 0 <= j < i
			// A[i] * (cnt of (A[j] where A[i] >= A[j])) - sum of (A[j] where A[i] >= A[j])
			ans += A[i] * qry(A[i] + N + 1, ft1) - qry(A[i] + N + 1, ft2);
			//~ // cout << i << ": " << qry(A[i] + N + 1, ft1) << ' ' << qry(A[i] + N + 1, ft2) << '\n';
			upd(A[i] + N + 1, 1, ft1);
			upd(A[i] + N + 1, A[i], ft2);
		}
		while (!st.empty()) st.pop();
		for (int i = 0; i <= N; i++) {
			while (!st.empty() && st.top() > mp(A[i], i)) st.pop();
			lft[i] = 0;
			if (!st.empty()) lft[i] = st.top().second + 1;
			st.emplace(A[i], i);
		}
		while (!st.empty()) st.pop();
		for (int i = N; i >= 0; i--) {
			while (!st.empty() && st.top() > mp(A[i], i)) st.pop();
			rig[i] = N;
			if (!st.empty()) rig[i] = st.top().second - 1;
			st.emplace(A[i], i);
		}
		int tans = 0;
		for (int i = 0; i <= N; i++) {
			// cout << lft[i] << ' ' << rig[i] << ' ' << A[i] << ' ' << (rig[i] - i + 1) * (i - lft[i] + 1) * A[i] << ' ' << A[i - 1] * (N - i + 1) << '\n';
			tans -= (rig[i] - i + 1) * (i - lft[i] + 1) * A[i];
			tans += A[i] * (N - i + 1);
		}
		//~ for (int i = 0; i <= N; i++)
			//~ tans -= 
		cout << ans + tans << '\n';
	}
}