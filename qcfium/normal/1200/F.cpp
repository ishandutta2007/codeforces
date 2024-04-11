#include <bits/stdc++.h>

#ifdef _WIN32
#	define getchar_fast _getchar_nolock
#else
#	define getchar_fast getchar_unlocked
#endif
int ri() {
	int r = 0, c, s = 0;
	for (;;) {
		c = getchar_fast();
		if (c == '-') {
			s = 1;
			break;
		}
		if (c <= '9' && c >= '0') {
			r = c - '0';
			break;
		}
	}
	for (;;) {
		c = getchar_fast();
		if (c < '0' || c > '9') break;
		r = r * 10 + c - '0';
	}
	if (s) r = -r;
	return r;
}
 

int main() {
	int n = ri();
	int k[n];
	for (int i = 0; i < n; i++) k[i] = (ri() % 2520 + 2520) % 2520;
	int m[n];
	std::vector<int> to[n];
	for (int i = 0; i < n; i++) {
		m[i] = ri();
		for (int j = 0; j < m[i]; j++) to[i].push_back(ri() - 1);
	}
	std::vector<int> hen(n * 2520);
	std::vector<std::vector<int> > rev(2520 * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2520; j++) {
			int from = i * 2520 + j;
			int via = (j + k[i]) % m[i];
			int too = to[i][via] * 2520 + (j + k[i]) % 2520;
			assert(too >= 0 && too < n * 2520);
			hen[from] = too;
			rev[too].push_back(from);
		}
	}
	std::vector<bool> used(n * 2520);
	std::vector<bool> tmp_used(n * 2520);
	std::vector<int> res(n * 2520, -1);
	for (int i = 0; i < n * 2520; i++) {
		if (used[i]) continue;
		int cur = i;
		while (!tmp_used[cur]) {
			tmp_used[cur] = true;
			cur = hen[cur];
		}
		std::set<int> all;
		int root = cur;
		do cur = hen[cur], all.insert(cur / 2520); while (cur != root);
		int cnt = all.size();
		
		std::queue<int> que;
		que.push(root);
		while (que.size()) {
			int cur = que.front();
			que.pop();
			if (used[cur]) continue;
			used[cur] = true;
			res[cur] = cnt;
			for (int i : rev[cur]) {
				if (!used[i]) que.push(i);
			}
		}
	}
	int q = ri();
	for (int i = 0; i < q; i++) {
		int x = ri() - 1;
		int y = ri();
		printf("%d\n", res[x * 2520 + (y % 2520 + 2520) % 2520]);
	}
	
	return 0;
}