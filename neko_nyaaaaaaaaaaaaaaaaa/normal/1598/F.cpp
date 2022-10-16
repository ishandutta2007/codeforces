#include <bits/stdc++.h>
using namespace std;

struct bracketString{
	int sum, mn;
	vector<int> ans;

	bracketString(string s) {
		sum = 0; mn = 0;
		ans.resize(s.size() + 1);
		
		int i = 0, mx = 0;
		for (char c: s) {
			if (c == '(') i++;
			else i--;
			mn = min(mn, i);
			
			if (i > 0) continue;
			if (-i >= mx) {
				ans[-i]++;
				mx = max(mx, -i);
			}
		}
		sum = i;
	}

	int get_ans(int x) {
		if (x >= ans.size()) return 0;
		return ans[x];
	}
};

vector<bracketString> s;
int n; int dp[1 << 20];

int go(int msk) {
	if (dp[msk] != -1) return dp[msk];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (msk & (1 << i)) {
			sum += s[i].sum;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!(msk & (1 << i))) {
			int extra = s[i].get_ans(sum);
			ans = max(ans, extra);

			if (s[i].mn + sum >= 0) {
				ans = max(ans, extra + go(msk ^ (1 << i)));
			}
		}
	}
	return dp[msk] = ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		s.push_back(bracketString(str));
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';

	return 0;
}