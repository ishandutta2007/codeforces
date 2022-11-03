#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}


int main() {
	int t = ri();
	for (int i = 0; i < t; i++) {
		int n = ri();
		int a[n];
		for (auto &i : a) i = ri();
		
		std::set<int> exs;
		int cnt[n + 1];
		memset(cnt, 0, sizeof(cnt));
		for (auto i : a) cnt[i]++;
		for (int i = 0; i <= n; i++) if (!cnt[i]) exs.insert(i);
		
		std::set<int> nonok;
		for (int i = 0; i < n; i++) if (a[i] != i) nonok.insert(i);
		
		std::vector<int> res;
		while (nonok.size()) {
			int mex = *exs.begin();
			if (mex == n) {
				int rep = *nonok.begin();
				res.push_back(rep);
				int tmp = a[rep];
				res.push_back(tmp);
				cnt[a[rep]]--;
				a[rep] = n;
				cnt[n]++;
				if (!--cnt[a[tmp]]) exs.insert(a[tmp]);
				a[tmp] = tmp;
				nonok.erase(tmp);
			} else {
				res.push_back(mex);
				if (!--cnt[a[mex]]) exs.insert(a[mex]);
				a[mex] = mex;
				exs.erase(mex);
				nonok.erase(mex);
			}
		}
		printf("%d\n", (int) res.size());
		for (auto i : res) printf("%d ", i + 1);
		puts("");
	}
	return 0;
}