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

int T, K, N, M, idx1, idx2, A[105], B[105];
bool inv;
vector<int> seq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> K >> N >> M;
		seq.clear();
		idx1 = idx2 = 1;
		inv = 0;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= M; i++) cin >> B[i];
		while (idx1 <= N || idx2 <= M) {
			if (idx1 > N) seq.pb(B[idx2++]);
			else if (idx2 > M) seq.pb(A[idx1++]);
			else {
				if (A[idx1] == 0) seq.pb(A[idx1++]);
				else if (B[idx2] == 0) seq.pb(B[idx2++]);
				else if (A[idx1] < B[idx2]) seq.pb(A[idx1++]);
				else seq.pb(B[idx2++]);
			}
		}
		for (int i : seq) {
			if (i == 0) K++;
			else if (i > K) inv = 1;
		}
		if (inv) cout << "-1\n";
		else {
			for (int i : seq) cout << i << ' ';
			cout << '\n';
		}
	}
}