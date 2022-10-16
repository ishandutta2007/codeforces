#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

bool check(int n, vector<int> a, int len) {
	RMQ<int> r(a);

	vector<int> st;
	for (int i = 0; i+len <= n; i++) {
		st.push_back(r.query(i, i+len));
	}
	sort(st.begin(), st.end());

	for (int i = 0; i < st.size(); i++) {
		if (st[i] != (i+1)) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	map<int, vector<int>> pos;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i+1);
	}

	vector<int> ans(n+1);
	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		if (pos[i].empty()) break;
		int ps = pos[i][0];

		if (pos[i].size() == 1 && (ps == l || ps == r)) {
			ans[n-i+1] = 1;

			if (ps == l) l++;
			else r--;
		} else {
			// the only compression length to check is r-l+1
			break;
		}
	}
	//cout << l << ' ' << r << '\n';
	// check length r-l+1
	if (r-l+1 >= 1) {
		ans[r-l+1] |= check(n, a, r-l+1);
	} 
	// also check len 1
	ans[1] |= check(n, a, 1);
	for (int i = 1; i <= n; i++) cout << ans[i];
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}