#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_STR_SIZE = 20;
const int sz = MAX_STR_SIZE * 1000000 + 5;
int n, k, cursz = 0;
string s;
int trie[sz][2];
bitset<sz> pos;

void insert(const string& str) {
	int cur = 0, strsz = str.length();
	foru(i, 0, strsz) {
		if (trie[cur][str[i] - '0'] == -1)trie[cur][str[i] - '0'] = ++cursz;
		cur = trie[cur][str[i] - '0'];
	}
}

void dfs(int src, int dep, const int& mxdep) {
	if (dep == mxdep)return;
	if (trie[src][0] == -1 || trie[src][1] == -1)pos[src] = 1;
	foru(i, 0, 2) {
		if (trie[src][i] != -1) {
			dfs(trie[src][i], dep + 1, mxdep);
			if (pos[trie[src][i]])pos[src] = 1;
		}
	}
}

void solve() {
	cin >> n >> k >> s;
	cursz = 0;
	foru(i, 0, MAX_STR_SIZE*n + 5) {
		trie[i][0] = trie[i][1] = -1;
		pos[i] = 0;
	}
	int myk = min(k, MAX_STR_SIZE), last0 = -1;
	for (int i = 0; i < max(0, k - MAX_STR_SIZE); i++) {
		if (s[i] == '0')last0 = i;
	}
	for (int i = max(0, k - MAX_STR_SIZE); i + myk <= n; i++) {
		if (last0 == -1 || (i - last0) > (k - myk)) {
			string str;
			for (int j = i; j < i + myk; j++)str.pb('1' - s[j] + '0');
			insert(str);
		}
		if (s[i] == '0')last0 = i;
	}
	dfs(0, 0, myk);
	if (!pos[0]) {
		cout << "NO\n";
		return;
	}
	else {
		cout << "YES\n";
		int cur = 0, rem = myk;
		for (int i = 0; i + myk < k; i++)cout << 0;
		bool out = 0;
		while (rem--) {
			if (out)cout << 0;
			else {
				if (trie[cur][0] == -1) {
					cout << 0;
					out = 1;
				}
				else if (pos[trie[cur][0]]) {
					cout << 0;
					cur = trie[cur][0];
				}
				else if (trie[cur][1] == -1) {
					cout << 1;
					out = 1;
				}
				else {
					cout << 1;
					cur = trie[cur][1];
				}
			}
		}
		cout << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}