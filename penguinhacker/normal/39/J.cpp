#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool pre[1000000], suf[1000000];
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	int n = t.size();
	pre[0] = suf[n] = 1;
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] && s[i - 1] == t[i - 1];
	for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] && s[i + 1] == t[i];
	vector<int> ans;
	for (int i = 0; i <= n; ++i) if (pre[i] && suf[i]) ans.push_back(i + 1);
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
	return 0;
}