#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, same[2];
string s[mxN], s2[mxN];
vector<int> dif[2], ans;

void solve() {
	same[0]=same[1]=0;
	dif[0].clear();
	dif[1].clear();
	ans.clear();
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s[i], s2[i]=s[i];
		reverse(s2[i].begin(), s2[i].end());
	}
	sort(s2, s2+n);
	for (int i=0; i<n; ++i) {
		if (s[i][0]==s[i].back()) {
			++same[s[i][0]-'0'];
			continue;
		}
		int pos=lower_bound(s2, s2+n, s[i])-s2;
		if (pos==n||s2[pos]!=s[i])
			dif[s[i][0]-'0'].push_back(i);
	}
	if (same[0]&&same[1]&&same[0]+same[1]==n) {
		cout << "-1\n";
		return;
	}
	if (dif[0].size()>dif[1].size())
		swap(dif[0], dif[1]);
	while(dif[1].size()>dif[0].size()+1) {
		ans.push_back(dif[1].back());
		dif[0].push_back(dif[1].back());
		dif[1].pop_back();
	}
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i+1 << " ";
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