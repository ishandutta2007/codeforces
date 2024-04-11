#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = (int)2e5 + 10;

vector <int> ed[maxn];
int d[maxn];

pair <pair <long long, int>, int> dfs(int v) {
	long long ans = 0;
	int mins = (int)1e9;
	int cnt = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		pair <pair <long long, int>, int> f = dfs(u);

		ans += f.first.first;
		mins = min(mins, f.first.second);
		cnt += f.second;
	}

	if (cnt % 2 == 0) {
		return make_pair(make_pair(ans + d[v], d[v]), 1);
	} else if (d[v] < mins) {
		return make_pair(make_pair(ans, mins), 1);
	} else {
		return make_pair(make_pair(ans - mins + d[v], d[v]), 1);
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		if (x != -1) {
			ed[x].push_back(i);
		}

		d[i] = y;
	}

	cout << dfs(1).first.first << endl;

	return 0;
}