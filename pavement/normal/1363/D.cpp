#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, M, K, C[1005];
string res;
vector<int> V[1005];

main() {
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= K; i++) {
			V[i].clear();
			cin >> C[i];
			for (int j = 1, x; j <= C[i]; j++) {
				cin >> x;
				V[i].pb(x);
			}
		}
		cout << "? " << N;
		for (int i = 1; i <= N; i++) cout << ' ' << i;
		cout << endl;
		cin >> M;
		int ans = -1, ans2;
		for (int lo = 1, hi = N, tmp; lo <= hi; ) {
			int mid = (lo + hi) >> 1;
			cout << "? " << mid - lo + 1;
			for (int i = lo; i <= mid; i++) cout << ' ' << i;
			cout << endl;
			cin >> tmp;
			if (tmp == M) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		assert(ans != -1);
		for (int i = 1; i <= K; i++) {
			bool hv = 0;
			for (int j : V[i])
				hv |= (j == ans);
			if (hv) {
				cout << "? " << N - C[i];
				sort(V[i].begin(), V[i].end());
				for (int j = 1; j <= N; j++)
					if (!binary_search(V[i].begin(), V[i].end(), j)) cout << ' ' << j;
				cout << endl;
				cin >> ans2;
				break;
			}
		}
		cout << '!';
		for (int i = 1; i <= K; i++) {
			bool hv = 0;
			for (int j : V[i])
				hv |= (j == ans);
			cout << ' ' << (hv ? ans2 : M);
		}
		cout << endl;
		cin >> res;
		if (res != "Correct") return 0;
	}
}