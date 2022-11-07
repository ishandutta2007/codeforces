#include <bits/stdc++.h>
using namespace std;

int link[200005], sz[200005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	vector<int> pos[26];
	cin >> n;
	for (int i = 0; i < n; i++) {
		link[i] = i, sz[i] = 1;
		cin >> s;
		for (char c : s)
			pos[c - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < (int)pos[i].size() - 1; j++) {
			if (find(pos[i][j]) != find(pos[i][j + 1]))
				n--, unite(pos[i][j], pos[i][j + 1]);
		}
	cout << n << '\n';
}