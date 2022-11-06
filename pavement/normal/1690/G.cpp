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

const int BLK_SZ = 315;
int T, N, M, idx, A[100005], L[100005], R[100005], blk[100005];
ii val[100005];
vector<pair<int, ii> > vec[100005];

void build(int x) {
	stack<int> S;
	for (int j = R[x]; j >= L[x]; j--) {
		while (!S.empty() && A[S.top()] >= A[j]) S.pop();
		if (!S.empty()) val[j] = val[S.top()], val[j].first++;
		else val[j] = mp(1, A[j]);
		S.push(j);
	}
	vec[x].clear();
	int sf = 1e16;
	for (int j = L[x]; j <= R[x]; j++) {
		if (A[j] < sf) {
			vec[x].eb(A[j], val[j]);
			sf = A[j];
		}
	}
	reverse(vec[x].begin(), vec[x].end());
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			L[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if ((i - 1) % BLK_SZ == 0) blk[i] = ++idx;
			else blk[i] = blk[i - 1];
		}
		for (int i = 1; i <= N; i++) {
			if (!L[blk[i]]) L[blk[i]] = i;
			R[blk[i]] = i;
		}
		for (int i = 1; i <= blk[N]; i++) {
			build(i);
		}
		for (int k, d; M--; ) {
			cin >> k >> d;
			A[k] -= d;
			build(blk[k]);
			int curr = 1e16, ret = 0;
			for (int i = 1; i <= blk[N]; i++) {
				auto it = lower_bound(vec[i].begin(), vec[i].end(), mp(curr, mp(-1ll, -1ll)));
				if (it != vec[i].begin()) {
					--it;
					ret += it->second.first;
					curr = it->second.second;
				}
			}
			cout << ret << ' ';
		}
		cout << '\n';
		idx = 0;
	}
}