#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = 998244353;
typedef vector<vector<int>> T;

T UNIT = {
	{1, 0},
	{0, 1},
};

T HAS_MAT = {
	{1, 2},
	{1, 2},
};

T NON_MAT = {
	{3, 0},
	{1, 2},
};

vector<T> st;

void merge(int v, int a, int b) {
	st[v][0][0] = st[v][0][1] = st[v][1][0] = st[v][1][1] = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				st[v][i][j] = (st[v][i][j] + 1LL*st[a][i][k]*st[b][k][j]) % M;
			}
		}
	}
}

void update(int node, int start, int end, int index, bool ex) {
	if (start == end) {
		if (ex) st[node] = HAS_MAT;
		else st[node] = NON_MAT;
	} else {
		int mid = (start + end)/2;
		
		if (start <= index && index <= mid) {update(2*node, start, mid, index, ex);}
		else {update(2*node+1, mid+1, end, index, ex);}

		merge(node, 2*node, 2*node+1);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	map<int, vector<int>> ent, ext;
	int l0, r0;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		if (i == 0) {
			l0 = l, r0 = r;
		} else {
			ent[l].push_back(i);
			ext[r+1].push_back(i);
		}
	}

	int ans = 0;
	st.resize(4*n, UNIT);
	for (int i = 1; i < n; i++) {
		update(1, 1, n-1, i, false);
	}
	for (int i = 0; i <= 300000; i++) {
		for (int j: ent[i]) {
			update(1, 1, n-1, j, true);
		}
		for (int j: ext[i]) {
			update(1, 1, n-1, j, false);
		}

		if (i >= l0 && i <= r0) {
			ans = (ans + st[1][1][1]) % M;
		} else {
			ans = (ans + st[1][0][1]) % M;
		}
	}
	cout << ans << '\n';

	return 0;
}