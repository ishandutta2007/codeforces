#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
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
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, H, t[26][200005], d[26][200005];
string str;

void calc(int p, int k, int ver) {
	if (d[ver][p] == -1) t[ver][p] = t[ver][p << 1] + t[ver][p << 1 | 1];
	else t[ver][p] = d[ver][p] * k;
}

void apply(int p, int value, int k, int ver) {
	t[ver][p] = value * k;
	if (p < N) d[ver][p] = value;
}

void build(int l, int r, int ver) {
	int k = 2;
	for (l += N, r += N - 1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; i--) calc(i, k, ver);
	}
}

void push(int l, int r, int ver) {
	int s = H, k = 1 << (H - 1);
	for (l += N, r += N - 1; s > 0; s--, k >>= 1)
		for (int i = l >> s; i <= r >> s; ++i)
			if (d[ver][i] != -1) {
				apply(i << 1, d[ver][i], k, ver);
				apply(i << 1 | 1, d[ver][i], k, ver);
				d[ver][i] = -1;
			}
}

void upd(int l, int r, int value, int ver) {
	r++;
	push(l, l + 1, ver);
	push(r - 1, r, ver);
	bool cl = 0, cr = 0;
	int k = 1;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (cl) calc(l - 1, k, ver);
		if (cr) calc(r, k, ver);
		if (l & 1) apply(l++, value, k, ver), cl = 1;
		if (r & 1) apply(--r, value, k, ver), cr = 1;
		}
	for (l--; r > 0; l >>= 1, r >>= 1, k <<= 1) {
		if (cl) calc(l, k, ver);
		if (cr && (!cl || l != r)) calc(r, k, ver);
	}
}

int qry(int l, int r, int ver) {
	r++;
	push(l, l + 1, ver);
	push(r - 1, r, ver);
	int res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[ver][l++];
		if (r & 1) res += t[ver][--r];
	}
	return res;
}

main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(d, -1, sizeof d);
	cin >> N >> M;
	H = sizeof(int) * 8 - __builtin_clz(N);
	cin >> str;
	for (int k = 0; k ^ 26; k++) {
		for (int i = N; i < N << 1; i++) t[k][i] = (str[i - N] == k + 'a');
		for (int i = N - 1; i > 0; i--) t[k][i] = t[k][i << 1] + t[k][i << 1 | 1];
	}
	for (int L, R; M--; ) {
		cin >> L >> R;
		L--, R--;
		if (R - L & 1) {
			int co = 0, cnt = 0;
			vector<ii> vec;
			for (int k = 0; k ^ 26; k++) {
				int x = qry(L, R, k);
				if (x & 1) co++;
				if (x > 1) vec.eb(k, x >> 1);
			}
			if (co) continue;
			for (int k = 0; k ^ 26; k++) upd(L, R, 0, k);
			for (auto i : vec) {
				upd(L + cnt, L + cnt + i.second - 1, 1, i.first);
				upd(R - cnt - i.second + 1, R - cnt, 1, i.first);
				cnt += i.second;
			}
		} else {
			int co = 0, cnt = 0, mid;
			vector<ii> vec;
			for (int k = 0; k ^ 26; k++) {
				int x = qry(L, R, k);
				if (x & 1) co++, mid = k;
				if (x > 1) vec.eb(k, x >> 1);
			}
			if (co != 1) continue;
			for (int k = 0; k ^ 26; k++) upd(L, R, 0, k);
			for (auto i : vec) {
				upd(L + cnt, L + cnt + i.second - 1, 1, i.first);
				upd(R - cnt - i.second + 1, R - cnt, 1, i.first);
				cnt += i.second;
			}
			upd((L + R) >> 1, (L + R) >> 1, 1, mid);
		}
	}
	for (int i = 0; i < N; i++)
		for (int k = 0; k ^ 26; k++)
			if (qry(i, i, k)) {
				cout << char(k + 'a');
				break;
			}
	cout << '\n';
}