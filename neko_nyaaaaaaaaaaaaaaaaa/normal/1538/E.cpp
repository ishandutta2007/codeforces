#include <bits/stdc++.h>
using namespace std;

#define int long long

tuple<string, string, int> merge(string p1, string s1, int c1, string p2, string s2, int c2) {
	int ans = c1+c2;
	string s = s1+p2;
	for (int i = 0; i < s.size(); i++) {
		if (s.substr(i, 4) == "haha") {
			ans++;
		}
	}

	string pr, sf;
	if (p1.size() >= 3) {
		pr = p1;
	} else {
		pr = p1+p2;
		pr = pr.substr(0, 3);
	}

	if (s2.size() >= 3) {
		sf = s2;
	} else {
		sf = s1+s2;
		if (sf.size() > 3) sf = sf.substr((int)sf.size()-3, 3);
	}

	return make_tuple(pr, sf, ans);
}

void solve() {
	int q; cin >> q;
	map<string, string> pre, suf;
	map<string, int> cnt; 

	string s, token;
	while (q--) {
		cin >> s >> token;
		if (token == ":=") {
			string gg; cin >> gg;
			int n = gg.size();

			if (n < 4) {
				pre[s] = suf[s] = gg;
				cnt[s] = 0;
			} else {
				cnt[s] = 0;
				for (int i = 0; i < n; i++) {
					if (gg.substr(i, 4) == "haha") {
						cnt[s]++;
					}
				}
				pre[s] = gg.substr(0, 3);
				suf[s] = gg.substr(n-3, 3);
			}
		} else {
			string a, b; cin >> a >> token >> b;
			auto [pf, sf, cc] = merge(pre[a], suf[a], cnt[a], pre[b], suf[b], cnt[b]);
			pre[s] = pf; suf[s] = sf; cnt[s] = cc;
		}
	}
	cout << cnt[s] << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}