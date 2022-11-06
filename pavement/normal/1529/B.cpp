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

int T, N, ans, tmp, idx, A[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = tmp = 0;
		idx = -1;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		sort(A + 1, A + 1 + N);
		for (int i = 1; i <= N; i++)
			if (A[i] <= 0) ans++;
			else {
				idx = i;
				break;
			}
		if (idx != -1) {
			// try MAX = A[idx]
			int prv = A[idx];
			for (int i = idx - 1; i >= 1; i--) {
				//cout << "NOW " << A[i] << ' ' << prv << '\n';
				if (llabs(prv - A[i]) >= A[idx]) prv = A[i], tmp++;
			}
			ans = max(ans, tmp + 1);
		}
		cout << ans << '\n';
	}
}