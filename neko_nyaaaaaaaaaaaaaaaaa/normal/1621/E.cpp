#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e15;

struct STLazy {
	int n;
	vector<int> tr, lz;

	STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8) {}

	void push(int v, int lo, int hi) {
		if (lz[v] != 0) {
			tr[v] += lz[v];
			if(lo+1 != hi) {
				lz[v*2] += lz[v];
				lz[v*2+1] += lz[v]; 
			}
			lz[v] = 0;
		}
	}

	void update(int v, int lo, int hi, int l, int r, int val) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return;

		if (lo >= l && hi <= r) {
			lz[v] += val; // put lazy tag here
			push(v, lo, hi);
			return;
		}

		int mid = (lo + hi) / 2;
		update(v*2, lo, mid, l, r, val);
		update(v*2 + 1, mid, hi, l, r, val);

		tr[v] = min(tr[2*v], tr[2*v+1]);
	}

	int query(int v, int lo, int hi, int l, int r) {
		push(v, lo, hi);
		if (lo >= hi || lo >= r || hi <= l) return INF;

		if (lo >= l && hi <= r) return tr[v];

		int mid = (lo + hi)/2;
		int p1 = query(v*2, lo, mid, l, r);
		int p2 = query(v*2 + 1, mid, hi, l, r);
		
		return min(p1, p2);
	}

	void update(int l, int r, int val) {
		update(1, 0, n, l, r, val);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	auto [u, v, i, j] = a;
	auto [p, q, ii, jj] = b;

	// u/v > p/q
	// u*q > p*v

	if (u*q == p*v) {
		return make_pair(i, j) < make_pair(ii, jj);
	} else {
		return u*q > p*v;
	}
}

void solve() {
	int n, m; cin >> n >> m;
	// events:
	// a teacher (value) ---> always go first
	// a student group full (average, groupid)
	// a student group ditched (average, groupid, studentid)

	vector<int> teach(n);
	for (int i = 0; i < n; i++) {
		cin >> teach[i];
	}

	vector<tuple<int, int, int, int>> gr;
	int petr = 0;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		vector<int> stu(k); int sum = 0;
		for (int j = 0; j < k; j++) {
			cin >> stu[j]; sum += stu[j];
		}

		gr.emplace_back(sum, k, i, -1);
		for (int j = 0; j < k; j++) {
			sum -= stu[j];
			gr.emplace_back(sum, k-1, i, petr);
			petr++;
			sum += stu[j];
		}
	}
	for (int i = 0; i < n; i++) {
		gr.emplace_back(teach[i], 1, -5, -5);
	}

	sort(gr.begin(), gr.end(), cmp);
	int k = gr.size() + 1;
	STLazy st(k);

	vector<int> pos(m);
	vector<int> postu(petr);

	for (int i = 0; i < gr.size(); i++) {
		auto [val, vall, grid, stid] = gr[i];
		//cout << val << ' ' << grid << ' ' << stid << '\n';
		if (grid == -5) {
			st.update(i+1, k, 1);
		} else if (stid == -1) {
			st.update(i+1, k, -1);
			pos[grid] = i+1;  
		} else {
			postu[stid] = i+1;
		}
	}

	// cout << "TREE\n";
	// for (int i = 0; i < k; i++) {
	// 	cout << st.query(i, i+1) << ' ';
	// }
	// cout << '\n';

	string ans(petr, '0');
	for (auto [val, vall, grid, stid]: gr) {
		if (grid == -5) {
			continue;
		} else if (stid == -1) {
			continue; 
		} else {
			st.update(pos[grid], k, 1);
			st.update(postu[stid], k, -1);

			if (st.query(0, k) >= 0) {
				ans[stid] = '1';
			}

			// cout << "TREE " << stid << '\n';
			// for (int i = 0; i < k; i++) {
			// 	cout << st.query(i, i+1) << ' ';
			// }
			// cout << '\n';

			st.update(pos[grid], k, -1);
			st.update(postu[stid], k, 1);
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}