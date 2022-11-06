#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, A[100005], ht[100005];
map<int, int> rowcnt, colcnt;
set<int> availone;

void die() {
	cout << "-1\n";
	exit(0);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int cprev = -1, cnt = N;
	vector<ii> vec;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = N; i >= 1; i--) {
		if (A[i] == 1) {
			vec.eb(cnt, i);
			availone.insert(cnt);
			ht[i] = cnt;
			cnt--;
			cprev = i;
		} else if (A[i] == 2) {
			if (availone.empty()) die();
			int x = *availone.rbegin();
			availone.erase(--availone.end());
			vec.eb(x, i);
			cprev = i;
		} else if (A[i] == 3) {
			if (cprev == -1) die();
			if (A[cprev] == 1) {
				availone.erase(ht[cprev]);
			}
			vec.eb(cnt, i);
			vec.eb(cnt, cprev);
			cnt--;
			cprev = i;
		}
	}
	bool cannot = 0;
	for (auto i : vec) {
		if (i.first < 1 || i.second < 1 || i.first > N || i.second > N) cannot = 1, rowcnt[i.first]++, colcnt[i.second]++;
	}
	if (cannot) return cout << "-1\n", 0;
	for (auto i : rowcnt)
		assert(i.second <= 2);
	for (auto i : colcnt)
		assert(i.second <= 2);
	cout << vec.size() << '\n';
	for (auto i : vec) cout << i.first << ' ' << i.second << '\n';
}