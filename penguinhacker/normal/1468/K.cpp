#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
map<int, int> mp;

int n;
string s;
vector<int> v;

bool check(int x, int y) {
	int cx = 0, cy = 0;
	for (int k : v) {
		if (cx + dx[k] != x || cy + dy[k] != y) {
			cx += dx[k];
			cy += dy[k];
		}
	}
	return cx == 0 && cy == 0;
}

void solve() {
	cin >> s, n = s.size();
	v.resize(n);
	for (int i = 0; i < n; ++i) v[i] = mp[s[i]];
	int cx = 0, cy = 0;
	for (int k : v) {
		cx += dx[k];
		cy += dy[k];
		if (check(cx, cy)) {
			cout << cx << " " << cy << "\n";
			return;
		}
	}
	cout << "0 0\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	mp['U'] = 0;
	mp['R'] = 1;
	mp['D'] = 2;
	mp['L'] = 3;
	int t; cin >> t;
	while(t--) solve();
	return 0;
}