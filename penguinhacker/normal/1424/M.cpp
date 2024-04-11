#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int color[26];
bool adj[26][26];
string ans;

void dfs(int v) {
    color[v] = 1;
    for (int i = 0; i < 26; ++i) {
		if (!adj[i][v]) continue;
		int u = i;
        if (color[u] == 0) {
			dfs(u);
        } else if (color[u] == 1) {
			cout << "IMPOSSIBLE";
			exit(0);
        }
    }
	ans.push_back(v + 'a');
    color[v] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, vector<string>>> pages(n);

	vector<bool> oc(26);

	for (int i = 0; i < n; ++i) {
		cin >> pages[i].first;
		for (int j = 0; j < k; ++j) {
			string s;
			cin >> s;
			for (char c : s) {
				oc[c - 'a'] = 1;
			}
			pages[i].second.push_back(s);
		}
	}
	sort(pages.begin(), pages.end());
	vector<string> ord;
	for (auto x : pages) for (string s : x.second) ord.push_back(s);
	//for (string s : ord) cout << s << "\n";
	int nm = n * k;
	assert(ord.size() == nm);

	for (int i = 0; i + 1 < nm; ++i) {
		string a = ord[i], b = ord[i + 1];
		int x = min(a.size(), b.size());
		bool bad = a.size() > b.size();
		for (int i = 0; i < x; ++i) {
			if (a[i] != b[i]) {
				bad = 0;
				adj[a[i] - 'a'][b[i] - 'a'] = 1;
				break;
			}
		}
		if (bad) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	//cout << "REACHED\n";
	for (int i = 0; i < 26; ++i) {
		if (!oc[i]) continue;
		if (color[i] == 0) dfs(i);
	}
	cout << ans;
	return 0;
}