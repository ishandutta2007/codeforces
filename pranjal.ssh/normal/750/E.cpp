#include <bits/stdc++.h>

using namespace std;

template <typename node>
struct ST {
#define mid ((l+r)>>1)
	int n;
	vector<node> T;

	ST(int n): n(n), T(4 * n + 10) {}

	void build(int no, int l, int r, const string &s) {
		if (l == r) {
			for (int i = 0; i < 5; ++i) T[no].a[i][i] = 0;
			if (s[l - 1] == '2') {
				T[no].a[0][1] = 0;
				T[no].a[0][0] = 1;				
			} else if (s[l - 1] == '0') {
				T[no].a[1][2] = 0;
				T[no].a[1][1] = 1;
			} else if (s[l - 1] == '1') {
				T[no].a[2][3] = 0;
				T[no].a[2][2] = 1;
			} else if (s[l - 1] == '6') {
				T[no].a[3][3] = 1;
				T[no].a[4][4] = 1;
			} else if (s[l - 1] == '7') {
				T[no].a[3][4] = 0;
				T[no].a[3][3] = 1;
			}
			return;
		}

		build(no << 1, l, mid, s);
		build(no << 1 | 1, mid + 1, r, s);
		T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
	}

	node qry(int no, int l, int r, int u, int v) {
		if (l >= u and r <= v)return T[no];
		if (v <= mid) return qry(no << 1, l, mid, u, v);
		else if (u >= mid + 1) return qry(no << 1 | 1, mid + 1, r, u, v);

		return node::merge(qry(no << 1, l, mid, u, v), qry(no << 1 | 1, mid + 1, r, u, v));
	}
#undef mid
};

struct node {
	int a[5][5];
	node() {
		for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) a[i][j] = 1e9;
	}
	static node merge(const node&x, const node&y) {
		node now;
		for (int i = 0; i < 5; ++i) {
			for (int j = i; j < 5; ++j) {
				for (int k = j; k < 5; ++k) {
					now.a[i][k] = min(now.a[i][k], x.a[i][j] + y.a[j][k]);
				}
			}
		}
		return now;
	}
};




int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n, q; cin >> n >> q;
	ST<node> T(n);
	string s; cin >> s;
	T.build(1, 1, n, s);

	while (q--) {
		int l, r; cin >> l >> r;
		int ans = T.qry(1, 1, n, l, r).a[0][4];
		if (ans > n) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}