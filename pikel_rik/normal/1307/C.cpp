#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.length();

	vector<int> single_count(26);
	vector<vector<ll>> cnt(26, vector<ll>(26));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			cnt[j][s[i] - 'a'] += single_count[j];
		}
		single_count[s[i] - 'a']++;
	}
	ll ans = *max_element(single_count.begin(), single_count.end());
	for (int i = 0; i < 26; i++) {
		ans = max(ans, *max_element(cnt[i].begin(), cnt[i].end()));
	}
	cout << ans << '\n';
	return 0;
}