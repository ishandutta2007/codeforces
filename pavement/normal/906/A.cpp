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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, F, T = (1 << 26) - 1, P[100005];
char C;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	F = N;
	for (int i = 1; i < N; i++) {
		P[i] = P[i - 1];
		cin >> C;
		if (C == '!') {
			P[i]++;
			cin >> S;
			int bm = 0;
			for (char c : S)
				bm |= 1 << (c - 'a');
			T &= bm;
		} else if (C == '.') {
			cin >> S;
			for (char c : S)
				if (T & (1 << (c - 'a'))) T ^= (1 << (c - 'a'));
		} else {
			P[i]++;
			cin >> C;
			if (T & (1 << (C - 'a'))) T ^= (1 << (C - 'a'));
		}
		assert(T);
		if (__builtin_popcount(T) == 1) F = min(F, i);
	}
	cout << (F == N ? 0 : P[N - 1] - P[F]) << '\n';
}