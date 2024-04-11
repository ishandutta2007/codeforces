#include <bits/stdc++.h>
using namespace std;

bool vis[10005][4];
string S;
set<string> ans;

void dfs(int l, int p) {
	if (l < 5) return;
	if (vis[l][p]) return;
	else vis[l][p] = 1;
	if (l >= 7) {
		if (p != 2) dfs(l - 2, 2);
		else {
			if (S[l] != S[l - 2] || S[l + 1] != S[l - 1]) dfs(l - 2, 2);
		}
	}
	if (l >= 8) {
		if (p != 3) dfs(l - 3, 3);
		else {
			if (S[l] != S[l - 3] || S[l + 1] != S[l - 2] || S[l + 2] != S[l - 1]) dfs(l - 3, 3);
		}
	}
}

int main() {
	cin >> S;
	dfs(S.length(), 0);
	for (int i = 0; i < S.length(); i++) {
		for (int j = 2; j <= 3; j++) if (vis[i][j]) ans.insert(S.substr(i, j));
	}
	printf("%d\n", ans.size());
	for (set<string>::iterator it = ans.begin(); it!=ans.end();it++) printf("%s\n", it->c_str());
}