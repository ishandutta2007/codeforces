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

int T, N;
vector<bool> af[300005];
string S[3];

void merge(int a, int b, bool c) {
	for (int i = 0; i < 3 * N; i++) af[i].clear();
	for (int i = 0, cnt = 0; i < 2 * N; i++) {
		if (S[a][i] - '0' == c && cnt != N) {
			cnt++;
			continue;
		}
		af[cnt].pb(S[a][i] - '0');
	}
	for (int i = 0, cnt = 0; i < 2 * N; i++) {
		if (S[b][i] - '0' == c && cnt != N) {
			cnt++;
			continue;
		}
		af[cnt].pb(S[b][i] - '0');
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < af[i].size(); j++) cout << af[i][j];
		cout << c;
	}
	for (int j = 0; j < af[N].size(); j++) cout << af[N][j];
	cout << '\n';
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> vec[2];
		for (int i = 0; i < 3; i++) {
			cin >> S[i];
			int o = 0, z = 0;
			for (int j = 0; j < 2 * N; j++)
				if (S[i][j] == '0') z++;
				else o++;
			if (o >= z) vec[1].pb(i);
			else vec[0].pb(i);
		}
		if (vec[0].size() >= 2) merge(vec[0][0], vec[0][1], 0);
		else merge(vec[1][0], vec[1][1], 1);
	}
}