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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, P, ans, msk, revb[200005], rev[200005];
bool A[200005][65], take[200005];
char c;
vector<int> act, curr, order;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> P;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> c;
			if (c == '1') A[i][j] = 1;
		}
	order.resize(N);
	iota(order.begin(), order.end(), 1);
	shuffle(order.begin(), order.end(), rng);
	for (int k = 0; k < min((int)order.size(), 30ll); k++) {
		int x = order[k], cnt = 0;
		for (int i = 0; i < (1 << P); i++) rev[i] = 0;
		for (int i = 0; i < P; i++) revb[i] = 0;
		for (int j = 1; j <= M; j++)
			if (A[x][j]) revb[cnt] = j, cnt++;
		for (int i = 1; i <= N; i++) {
			msk = 0;
			for (int j = 0; j < cnt; j++)
				if (A[i][revb[j]]) msk |= (1 << j);
			assert(msk < (1 << cnt));
			rev[msk]++;
		}
		for (int i = 0; i < (1 << cnt); i++) {
			if (!rev[i]) continue;
			for (int s = i; s; s = (s - 1) & i)
				rev[s ^ i] += rev[i];
		}
		for (int i = 0; i < (1 << cnt); i++)
			if (rev[i] >= (N + 1) / 2 && (int)__builtin_popcountll(i) > ans) {
				ans = (int)__builtin_popcountll(i);
				act.clear();
				for (int j = 0; j < cnt; j++)
					if (i & (1 << j))
						act.pb(revb[j]);
			}
	}
	for (int i : act) take[i] = 1;
	for (int i = 1; i <= M; i++) cout << take[i];
	cout << '\n';
}