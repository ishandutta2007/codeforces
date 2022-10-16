#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

#define int long long

bool no_way_home(string s, string t) {
	sort(s.begin(), s.end());
	return s >= t;
}

const int INF = 1e15;

void solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	// make s smaller than t

	if (s < t) {
		cout << "0\n"; return;
	}
	if (no_way_home(s, t)) {
		cout << "-1\n"; return;
	}

	vector<vector<int>> pos(26);
	for (int i = n-1; i >= 0; i--) {
		pos[s[i] - 'a'].push_back(i);
	}

	FT tr(n+3);
	for (int i = 0; i < n; i++) {
		tr.update(i, i);
		tr.update(i+1, -i);
	}

	int ans = INF, precost = 0;
	for (int i = 0; i < n; i++) {
		// make this character smaller than t?
		int mnc = INF;
		for (char c = 'a'; c < t[i]; c++) {
			if (pos[c - 'a'].empty()) continue;

			// move this to position i
			int ps = pos[c - 'a'].back();
			mnc = min(mnc, abs(tr.query(ps+1) - i)); 
		}
		ans = min(ans, mnc + precost);

		// make this character equal to t
		if (pos[t[i] - 'a'].empty()) break;

		int ps = pos[t[i] - 'a'].back();
		pos[t[i] - 'a'].pop_back();

		precost += abs(tr.query(ps+1) - i);
		tr.update(0, 1);
		tr.update(ps, -1);
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