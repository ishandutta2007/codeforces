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

int N, Q, A[200005], out[200005];
vector<int> seq;
vector<ii> qu[200005];
set<int> curr;
map<ii, vector<int> > mpt;
priority_queue<ii> pq;
ordered_set<int> O;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		pq.emplace(A[i], i);
	}
	while (!pq.empty()) {
		mpt.clear();
		auto x = pq.top();
		pq.pop();
		vector<int> vec;
		vec.pb(x.second);
		while (!pq.empty() && pq.top().first == x.first) {
			vec.pb(pq.top().second);
			pq.pop();
		}
		for (int j : vec) {
			auto let = curr.upper_bound(j);
			int le;
			if (let != curr.begin()) --let, le = *let;
			else le = 0;
			auto rit = curr.lower_bound(j);
			int ri;
			if (rit != curr.end()) ri = *rit;
			else ri = N + 1;
			mpt[mp(le, ri)].pb(j);
		}
		for (auto i : mpt) {
			if (A[i.first.second] >= x.first)
				for (int j : i.second) seq.pb(j), curr.insert(j);
		}
		for (auto it = mpt.rbegin(); it != mpt.rend(); ++it)
			if (A[it->first.second] < x.first)
				for (int j : it->second) seq.pb(j), curr.insert(j);
	}
	cin >> Q;
	for (int i = 1, X, K; i <= Q; i++) {
		cin >> K >> X;
		qu[K].eb(X, i);
	}
	for (int i = 0; i < seq.size(); i++) {
		O.insert(seq[i]);
		for (auto j : qu[i + 1])
			out[j.second] = A[*O.find_by_order(j.first - 1)];
	}
	for (int i = 1; i <= Q; i++) cout << out[i] << '\n';
}