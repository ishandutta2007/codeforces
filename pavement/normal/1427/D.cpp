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

int N, C[55];
bool proc[55];
vector<vector<int> > out;

void perf(vector<int> D) {
	vector<vector<int> > chunks;
	int pt = 1;
	for (int i : D) {
		vector<int> curr;
		for (int j = pt; j < pt + i; j++) curr.pb(C[j]);
		chunks.pb(curr);
		pt += i;
	}
	reverse(chunks.begin(), chunks.end());
	pt = 0;
	for (auto i : chunks)
		for (int j : i) C[++pt] = j;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1, mx = N, mi = 1; i <= N; i++) {
		vector<int> D;
		int cnt = 0;
		if ((i & 1) ^ (N & 1)) {
			for (int j = 1; j <= N; j++)
				if (proc[C[j]]) {
					if (cnt) D.pb(cnt), cnt = 0;
					D.pb(1);
				} else if (C[j] == mx) {
					if (cnt) D.pb(cnt), cnt = 0;
					cnt++;
				} else {
					cnt++;
				}
			if (cnt) D.pb(cnt);
			proc[mx] = 1;
			mx--;
		} else {
			for (int j = 1; j <= N; j++)
				if (proc[C[j]]) {
					if (cnt) D.pb(cnt), cnt = 0;
					D.pb(1);
				} else if (C[j] == mi) {
					if (cnt) D.pb(cnt), cnt = 0;
					cnt++;
				} else {
					cnt++;
				}
			if (cnt) D.pb(cnt);
			proc[mi] = 1;
			mi++;
		}
		if (D.size() > 1) {
			out.pb(D);
			perf(D);
		}
	}
	cout << out.size() << '\n';
	for (auto i : out) {
		cout << i.size() << ' ';
		for (int j : i) cout << j << ' ';
		cout << '\n';
	}
}