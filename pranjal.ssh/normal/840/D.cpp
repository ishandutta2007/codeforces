#include <bits/stdc++.h>
using namespace std;

vector<int> T, L, R;
int make(int x) {
	T.push_back(x), L.push_back(0), R.push_back(0);
	return T.size() - 1;
}
int upd(int no, int l, int r, int pos) {
	if (l == r) {
		int x = make(T[no] + 1);
		return x;
	}
	int mid = (l + r) >> 1;
	int x = make(T[no] + 1);
	if (pos <= mid) {
		R[x] = R[no];
		int n = upd(L[no], l, mid, pos);
		L[x] = n;
	} else {
		L[x] = L[no];
		int n = upd(R[no], mid+1, r, pos);
		R[x] = n;
	}
	return x;
}

int qry(int i, int j, int l, int r, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int x = T[L[j]] - T[L[i]];
	if (k <= x) return qry(L[i], L[j], l, mid, k);
	return qry(R[i], R[j], mid+1, r, k-x);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	T = L = R = {0};
	vector<int> a(n + 1);
	vector<int> root(n + 1);
	vector<vector<int>> pos(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
		root[i] = upd(root[i - 1], 1, n, a[i]);
	}

	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		int x = (r - l + 1) / k + 1;
		int y = x;
		bool f = 0;
		for (int i = 0; i < k - 1; ++i) {
			int c = qry(root[l-1], root[r], 1, n, y);
			int no = upper_bound(pos[c].begin(), pos[c].end(), r) - lower_bound(pos[c].begin(), pos[c].end(), l);
			// cout << l << " " << r << " " << y << " " << c << " " << no << "\n";
			if (no >= x) {
				cout << c << "\n";
				f = 1;
				break;
			}
			y += x;
		}
		if (!f)
		cout << "-1\n";
	}


	return 0;
}