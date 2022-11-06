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

int N, pos1, pos2, A[200005], B[200005], P[200005], R[200005];
vector<int> st[200005], ed[200005];
vector<ii> vec[200005];
set<int> T;
set<ii> S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		vec[A[i]].eb(B[i], i);
	}
	for (int i = 1; i <= N; i++) {
		for (auto j : vec[i])
			S.emplace(j.first, j.second);
		P[S.begin()->second] = i;
		S.erase(S.begin());
	}
	for (int i = 1; i <= N; i++) R[P[i]] = i;
	for (int i = 1; i <= N; i++) {
		st[A[R[i]]].pb(i);
		ed[B[R[i]]].pb(i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j : st[i]) T.insert(j);
		auto it = T.lower_bound(A[R[i]]);
		if (it != T.end() && *it <= B[R[i]]) {
			if (*it == i) ++it;
		}
		if (it != T.end() && *it <= B[R[i]]) {
			pos1 = i;
			pos2 = *it;
		}
		for (int j : ed[i]) T.erase(j);
	}
	if (pos1) {
		cout << "NO\n";
		for (int i = 1; i <= N; i++) cout << P[i] << ' ';
		cout << '\n';
		swap(P[R[pos1]], P[R[pos2]]);
		for (int i = 1; i <= N; i++) cout << P[i] << ' ';
		cout << '\n';
	} else {
		cout << "YES\n";
		for (int i = 1; i <= N; i++) cout << P[i] << ' ';
		cout << '\n';
	}
}