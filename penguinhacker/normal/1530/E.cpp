#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt[26];
string s;

void solve() {
	cin >> s, n=s.size();
	sort(s.begin(), s.end());
	if (s[0]==s.back()) {
		cout << s << "\n";
		return;
	}
	memset(cnt, 0, sizeof(cnt));
	for (char c : s)
		++cnt[c-'a'];
	for (int i=0; i<26; ++i)
		if (cnt[i]==1) {
			char x='a'+i;
			cout << x;
			for (char c : s)
				if (c!=x)
					cout << c;
			cout << "\n";
			return;
		}
	vector<pair<char, int>> v;
	for (int i=0; i<26; ++i)
		if (cnt[i])
			v.emplace_back('a'+i, cnt[i]);
	if (v[0].second-2<=(n-2)/2) {
		string ans;
		ans.push_back(v[0].first);
		ans+=ans;
		cnt[v[0].first-'a']-=2;
		for (int i=0; i<n-2; ++i) {
			for (int j=0; j<26; ++j) {
				if (cnt[j]&&!(ans[0]==ans.back()&&j==ans[0]-'a')) {
					--cnt[j];
					ans+=(char)('a'+j);
					break;
				}
			}
		}
		cout << ans << "\n";
		return;
	}
	cout << v[0].first << v[1].first;
	--cnt[v[0].first-'a'];
	--cnt[v[1].first-'a'];
	if (v.size()>2) {
		cout << string(cnt[v[0].first-'a'], v[0].first);
		cnt[v[0].first-'a']=0;
		cout << v[2].first;
		--cnt[v[2].first-'a'];
		for (auto& x : v)
			cout << string(cnt[x.first-'a'], x.first);
		cout << "\n";
		return;
	}
	reverse(v.begin(), v.end());
	for (auto& x : v)
		cout << string(cnt[x.first-'a'], x.first);
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}