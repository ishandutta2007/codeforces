#include <bits/stdc++.h>

int N;
std::string str;
int tp[1100000], val[1100000], ch[1100000][2];
int mv[1100000], ok[1100000];

void dfs (int n) {
	if (tp[n] == 0) return;
	else if (tp[n] == 1) {
		dfs (ch[n][0]); dfs (ch[n][1]);
		if (val[ch[n][0]] && val[ch[n][1]]) mv[ch[n][0]] = mv[ch[n][1]] = 1;
		else if (val[ch[n][0]]) mv[ch[n][1]] = 1;
		else if (val[ch[n][1]]) mv[ch[n][0]] = 1;
		val[n] = val[ch[n][0]] & val[ch[n][1]];
	} else if (tp[n] == 2) {
		dfs (ch[n][0]); dfs (ch[n][1]);
		if (!val[ch[n][0]] && !val[ch[n][1]]) mv[ch[n][0]] = mv[ch[n][1]] = 1;
		else if (!val[ch[n][0]]) mv[ch[n][1]] = 1;
		else if (!val[ch[n][1]]) mv[ch[n][0]] = 1;
		val[n] = val[ch[n][0]] | val[ch[n][1]];
	} else if (tp[n] == 3) {
		dfs (ch[n][0]); dfs (ch[n][1]);
		mv[ch[n][0]] = mv[ch[n][1]] = 1;
		val[n] = val[ch[n][0]] ^ val[ch[n][1]];
	} else if (tp[n] == 4) {
		dfs (ch[n][0]);
		mv[ch[n][0]] = 1;
		val[n] = !val[ch[n][0]];
	}
}

void dfs2 (int n) {
	ok[n] = 1;
	if (tp[n] == 0) return;
	else if (tp[n] == 4) {
		if (mv[ch[n][0]]) dfs2 (ch[n][0]);
	} else {
		if (mv[ch[n][0]]) dfs2 (ch[n][0]);
		if (mv[ch[n][1]]) dfs2 (ch[n][1]);
	}
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> str;
		if (str == "IN") {
			tp[i] = 0;
			std::cin >> val[i];
		} else if (str == "AND") {
			tp[i] = 1;
			std::cin >> ch[i][0] >> ch[i][1];
		} else if (str == "OR") {
			tp[i] = 2;
			std::cin >> ch[i][0] >> ch[i][1];
		} else if (str == "XOR") {
			tp[i] = 3;
			std::cin >> ch[i][0] >> ch[i][1];
		} else if (str == "NOT") {
			tp[i] = 4;
			std::cin >> ch[i][0];
		}
	}
	dfs (1);
	dfs2 (1);
	for (int i = 1; i <= N; ++i) {
		if (tp[i] == 0) std::cout << (val[1] ^ ok[i]);
	}
	std::cout << "\n";
	return 0;
}