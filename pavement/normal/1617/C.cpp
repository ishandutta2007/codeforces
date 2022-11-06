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

int T, N, cnt, A[100005];
bool inv, yep[100005], done[100005];
vector<ii> R;
multiset<int> curr;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		R.clear();
		curr.clear();
		inv = 0;
		cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) yep[i] = done[i] = 0;
		for (int i = 1; i <= N; i++) cin >> A[i];
		sort(A + 1, A + 1 + N);
		for (int i = 1; i <= N; i++)
			if (binary_search(A + 1, A + 1 + N, i)) {
				cnt++;
				yep[i] = done[i] = 1;
			}
		for (int i = 1; i <= N; i++) {
			if (A[i] > N || (A[i] <= N && !yep[A[i]])) R.eb(0, (A[i] - 1) / 2);
			if (A[i] <= N) yep[A[i]] = 0;
		}
		sort(R.begin(), R.end());
		reverse(R.begin(), R.end());
		//for (auto [l, r] : R) cout << l << ' ' << r << '\n';
		for (int i = 1; i <= N; i++) {
			if (done[i]) continue;
			while (!R.empty() && R.back().first <= i) {
				curr.insert(R.back().second);
				R.ppb();
			}
			if (!curr.empty() && *curr.begin() >= i) curr.erase(curr.begin());
			else inv = 1;
		}
		if (inv) cout << "-1\n";
		else cout << N - cnt << '\n';
	}
}