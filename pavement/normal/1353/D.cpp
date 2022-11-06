#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, arr[200005];
priority_queue<iii> pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int len, st, end, op = 1;
		cin >> N;
		pq.emplace(N, -1, N);
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();
			tie(len, st, end) = tmp;
			st = -st;
			if ((end - st + 1) & 1) {
				arr[(st + end) / 2] = op;
				if (st < (st + end) / 2) pq.emplace((st + end) / 2 - st, -st, (st + end) / 2 - 1);
				if ((st + end) / 2 < end) pq.emplace(end - (st + end) / 2, -((st + end) / 2 + 1), end);
			} else {
				arr[(st + end - 1) / 2] = op;
				if (st < (st + end - 1) / 2) pq.emplace((st + end - 1) / 2 - st, -st, (st + end - 1) / 2 - 1);
				if ((st + end - 1) / 2 < end) pq.emplace(end - (st + end - 1) / 2, -((st + end - 1) / 2 + 1), end);
			}
			op++;
		}
		for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
		cout << '\n';
	}
}