#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 3e5 + 3;

struct segment_tree {
	int last;
	vector<int> Min, push;

	segment_tree(int n) {
		last = n - 1;
		Min.resize(4 * n);
		push.resize(4 * n);
	}

	void pushing(int v) {
		Min[v * 2 + 1] += push[v];
		push[v * 2 + 1] += push[v];
		Min[v * 2 + 2] += push[v];
		push[v * 2 + 2] += push[v];
		push[v] = 0;
	}

	void upd(int v) {
		Min[v] = min(Min[v * 2 + 1], Min[v * 2 + 2]);
	}

	void add1(int v, int l, int r, int right, int x) {
		//cout << "add" << " " << v << " " << l << " " << r << " " << right << " " << x << '\n';
		if (l > right) return;
		if (r <= right) {
			Min[v] += x;
			push[v] += x;
			return;
		}
		pushing(v);
		int m = ((l + r) >> 1);
		add1(v * 2 + 1, l, m, right, x);
		add1(v * 2 + 2, m + 1, r, right, x);
		upd(v);
	}

	void add1(int r, int x) {
		add1(0, 0, last, r, x);
	}

	int get(int v, int l, int r, int right) {
		//cout << "get" << " " << v << " " << l << " " << r << " " << right << '\n';

		if (l > right) return inf;
		if (r <= right) return Min[v];

		pushing(v);
		int m = ((l + r) >> 1);

		return min(get(v * 2 + 1, l, m, right), get(v * 2 + 2, m + 1, r, right));
	}

	int get(int r) {
		return get(0, 0, last, r);
	}
};

int n, a[max_n], b[max_n], sort1[max_n];

void scan() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		sort1[i] = i;
	}
	for(int i = 0;i < n;i++) {
		cin >> b[i];
		b[i]--;
	}
	sort(sort1, sort1 + n, [](int v1, int v2) {return a[v1] > a[v2];});
}

void solve() {
	scan();

	segment_tree c = segment_tree(n);

	int id = 0;


	/*for(int i = 0;i < n;i++) cout << a[i] << " ";
	cout << '\n';
	for(int i = 0;i < n;i++) cout << sort1[i] << " ";
	cout << '\n';
	for(int i = 0;i < n;i++) cout << b[i] << " ";
	cout << '\n';*/

	for(int i = 0;i < n;i++) {
		cout << a[sort1[id]] << " ";


		//for(int j = 0;j < n;j++) cout << c.get(j) << " ";
		//cout << '\n';

		c.add1(b[i], 1);

		while(id < n && c.get(sort1[id]) >= 1) c.add1(sort1[id++], -1);
	}

}


signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    srand(0);

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}