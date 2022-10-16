#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long ans;
int main() {
	string s, t;
	cin >> s >> t;
	
	if(s.size() < t.size()) {
		sort(s.rbegin(), s.rend());
		cout << s << endl;
		return 0;
	}

	vector<int> vec(10);
	for(auto &v : s) vec[v - '0']++;

	int n = s.size();

	//k
	auto solve = [&](int k) {
		string res = "";
		auto cnt = vec;

		for(int i = 0; i < k; i++) {
			int d = t[i] - '0';
			if(--cnt[d] < 0) return;
			res += t[i];
		}

		if(k != n) {
			bool ok = 0;
			for(int d = t[k] - '1'; d >= 0; d--) {
				if(cnt[d] - 1 >= 0) {
					cnt[d]--;
					res += (char)d + '0';
					ok = 1;
					break;
				}
			}
			if(!ok) return;
		}

		while(res.size() < n) {
			for(int d = 9; d >= 0; d--) {
				if(--cnt[d] >= 0) {
					res += (char)d + '0';
					break;
				}
			}
		}

		ans = max(ans, stoll(res));
	};

	for(int k = 0; k <= n; k++) solve(k);

	cout << ans << endl;

	return 0;
}