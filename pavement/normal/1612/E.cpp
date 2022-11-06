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

int N, M, K, out, s[200005], tmps[200005];
ii ans = mp(0, 1);
vector<int> vec[200005], vec2;
priority_queue<int> pq;
priority_queue<ii> pq2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> M >> K;
		vec[M].pb(K);
		s[M] += K;
	}
	for (int i = 1; i <= 19; i++) {
		while (!pq.empty()) pq.pop();
		for (int j = 1; j <= 200000; j++) {
			tmps[j] = 0;
			for (auto k : vec[j])
				tmps[j] += min(k, i);
			pq.emplace(tmps[j]);
		}
		int curr = 0;
		for (int j = 0; j < i; j++) {
			curr += pq.top();
			pq.pop();
		}
		if (ans.first * i < curr * ans.second) {
			ans = mp(curr, i);
			out = i;
		}
	}
	int curr = 0;
	sort(s + 1, s + 200001, greater<int>());
	for (int i = 1; i <= 19; i++)
		curr += s[i];
	for (int X = 20; X <= 200000; X++) {
		curr += s[X];
		// curr / X
		if (ans.first * X < curr * ans.second) {
			ans = mp(curr, X);
			out = X;
		}
	}
	for (int j = 1; j <= 200000; j++) {
		tmps[j] = 0;
		for (auto k : vec[j])
			tmps[j] += min(k, out);
		pq2.emplace(tmps[j], j);
	}
	for (int j = 0; j < out; j++) {
		vec2.pb(pq2.top().second);
		pq2.pop();
	}
	cout << vec2.size() << '\n';
	for (int i : vec2) cout << i << ' ';
	cout << '\n';
}