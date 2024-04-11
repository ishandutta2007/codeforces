//Qzy___
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 42;

int n, k, a[N];
vector<vector<int> > opt;

void dfs(int nw) {
	if (nw == k) {
		int flag = 1, ct = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == -1 || a[i] == 0)
				flag &= ct == 0;
			if (a[i] == -1 || a[i] == 1)
				ct++;
		}
		if (!flag) {
			puts("REJECTED");
			exit(0);
		}
		return;
	}
	vector<int> lst(opt[nw].size());
	int ct[2] = {0};
	for (int i = 0; i < opt[nw].size(); i++) {
		lst[i] = a[opt[nw][i]];
		if (a[opt[nw][i]] != -1) ct[a[opt[nw][i]]]++;
	}
	for (int j = 0; j < ct[0]; j++) a[opt[nw][j]] = 0;
	for (int j = ct[0]; j < opt[nw].size(); j++) a[opt[nw][j]] = 1;
	for (int i = ct[0]; i <= opt[nw].size() - ct[1]; i++) {
		if (i != ct[0]) a[opt[nw][i - 1]] = 0;
		dfs(nw + 1);
	}
	for (int i = 0; i < opt[nw].size(); i++)
		a[opt[nw][i]] = lst[i];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0, x; i < k; i++) {
		scanf("%d", &x);
		opt.push_back(vector<int>(x));
		for (int j = 0; j < x; j++)
			scanf("%d", &opt[i][j]);
	}
	for (int i = 1; i <= n; i++) a[i] = -1;
	dfs(0), puts("ACCEPTED");
	return 0;
}