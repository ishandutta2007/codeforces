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

int TC, N, ans, ft[100005], ST[400005], E[400005], val[26][400005];
char S[100005], T[100005];
bool del[100005];

inline int ls(int x) { return x & -x; }

int del_qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void del_upd(int p) {
	for (; p <= N; p += ls(p)) ft[p]++;
}

void build(int s = 1, int e = N, int p = 1) {
	ST[p] = s;
	E[p] = e;
	for (int i = 0; i < 26; i++) val[i][p] = 1e9;
	if (ST[p] == E[p]) return;
	int M = (s + e) >> 1;
	build(s, M, p << 1);
	build(M + 1, e, p << 1 | 1);
}

void upd(int t, int p, int v, int idx = 1) {
	if (ST[idx] == E[idx]) {
		val[t][idx] = (v == 1 ? p : 1e9);
		return;
	}
	int M = (ST[idx] + E[idx]) >> 1;
	if (p <= M) upd(t, p, v, idx << 1);
	else upd(t, p, v, idx << 1 | 1);
	val[t][idx] = min(val[t][idx << 1], val[t][idx << 1 | 1]);
}

int qry(int t, int l, int r, int idx = 1) {
	if (l > E[idx] || r < ST[idx]) return 1e9;
	if (l <= ST[idx] && E[idx] <= r) return val[t][idx];
	return min(qry(t, l, r, idx << 1), qry(t, l, r, idx << 1 | 1));
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
			S[i] -= 'a';
		}
		for (int i = 1; i <= N; i++) {
			cin >> T[i];
			T[i] -= 'a';
		}
		build(1, N);
		for (int i = 1; i <= N; i++) upd(S[i], i, 1);
		//cout << root[0]->val << '\n';
		//cout << "?\n";
		ans = LLONG_MAX;
		for (int i = 1; i <= N; i++) {
			if (S[i] < T[i]) {
				ans = 0;
				break;
			} else if (S[i] > T[i]) break;
		}
		//cout << "?\n";
		if (ans == 0) {
			cout << "0\n";
			continue;
		}
		//cout << "?\n";
		for (int i = 1, curp = 1, curr_ans = 0; i <= N; i++) {
			//cout << "? " << i << ' ' << curp << '\n';
			if (del[i]) continue;
			if (S[i] < T[curp]) {
				ans = min(ans, curr_ans);
				break;
			}
			//cout << "CURR " << i << ' ' << curp << '\n';
			for (int j = T[curp] - 1; j >= 0; j--) {
				int tmp = qry(j, i + 1, N);
				if (tmp == 1e9) continue;
				//cout << j << " --> " << tmp << '\n';
				ans = min(ans, curr_ans + tmp - i - (del_qry(tmp) - del_qry(i - 1)));
			}
			if (S[i] == T[curp]) {
				curp++;
				continue;
			}
			int tmp = qry(T[curp], i + 1, N);
			if (tmp == 1e9) break;
			//cout << "@ " << i << ' ' << curp << ' ' << tmp << '\n';
			upd(T[curp], tmp, -1);
			del_upd(tmp);
			del[tmp] = 1;
			//cout << "%%" << tmp << '\n';
			curr_ans += tmp - i - (del_qry(tmp - 1) - del_qry(i - 1));
			//cout << "##\n";
			i--;
			curp++;
		}
		cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
		for (int i = 1; i <= N; i++) ft[i] = del[i] = 0;
	}
}