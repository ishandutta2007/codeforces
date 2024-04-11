#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7, inf = INT_MAX;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

int n, m, c[N];
string a[N];
pair<string, string> b[N];

void convert(string& s) {
	for (char& ch : s) {
		if (isupper(ch)) {
			ch = tolower(ch);
		}
	}
}

int visited[3 * N], cur_i;
vector<int> g[3 * N];

void dfs(int x) {
	visited[x] = cur_i;
	for (auto& i : g[x]) {
		if (visited[i] == -1) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		convert(a[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
		convert(b[i].first);
		convert(b[i].second);
	}

	map<string, int> mp;
	int cur = 0;

	for (int i = 0; i < n; i++) {
		if (!mp.count(a[i])) {
			mp[a[i]] = cur++;
		}
	}

	vector<tuple<int, int, int>> words;
	for (int i = 0; i < m; i++) {
		if (!mp.count(b[i].first)) {
			mp[b[i].first] = cur++;
		}
		if (!mp.count(b[i].second)) {
			mp[b[i].second] = cur++;
		}
		g[mp[b[i].second]].push_back(mp[b[i].first]);
		c[i] = count(b[i].second.begin(), b[i].second.end(), 'r');
		words.emplace_back(c[i], b[i].second.length(), i);
	}

	sort(words.begin(), words.end());

	for (auto& [c, l, i] : words) {
		cur_i = i;
		int idx = mp[b[i].second];
		if (visited[idx] == -1) {
			dfs(idx);
		}
	}

	ll ans_r = 0, ans_l = 0;
	for (int i = 0; i < n; i++) {
		int rr = count(a[i].begin(), a[i].end(), 'r'), ll = a[i].length();
		int idx = visited[mp[a[i]]];
		if (idx != -1) {
			if (c[idx] < rr) {
				rr = c[idx];
				ll = b[idx].second.length();
			} else if (c[idx] == rr and b[idx].second.length() < a[i].length()) {
				ll = b[idx].second.length();
			}
		}
		ans_r += rr;
		ans_l += ll;
	}

	cout << ans_r << ' ' << ans_l << '\n';
	return 0;
}