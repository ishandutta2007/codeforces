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

int T, N, M, A[200005], B[200005], deg[200005], L[200005], R[200005];
vector<int> vec[200005];
queue<int> Q;
set<int> S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) {
			cin >> B[i];
			A[i] = A[i] - B[i] + A[i - 1];
			if (A[i]) S.insert(i);
		}
		for (int i = 1; i <= M; i++) {
			cin >> L[i] >> R[i];
			L[i]--;
			deg[i] = !!A[L[i]] + !!A[R[i]];
			if (deg[i] == 0) Q.push(i);
			vec[L[i]].pb(i);
			vec[R[i]].pb(i);
		}
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			auto it = S.lower_bound(L[x]);
			vector<set<int>::iterator> to_del;
			while (it != S.end() && *it <= R[x]) {
				for (int j : vec[*it]) {
					deg[j]--;
					if (deg[j] == 0) Q.push(j);
				}
				to_del.pb(it);
				++it;
			}
			for (auto i : to_del) S.erase(i);
		}
		if (S.empty()) cout << "YES\n";
		else cout << "NO\n";
		S.clear();
		for (int i = 1; i <= N; i++) vec[i].clear();
	}
}