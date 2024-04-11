#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <random>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "queuemin2"

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)1e2 + 7;
const int inf = (int)1e9 + 7;

string used, ans[dd];

string nxt() {
	for (int i = 9; i > 0; --i)
		if (used[i] != 'z') {
			used[i]++;
			for (int j = i + 1; j < 10; ++j)
				used[j] = 'a';
			return used;
		}
	used[0]++;
	for (int i = 1; i < 10; ++i)
		used[i] = 'a';
	return used;
}

int solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	used = "A";
	for (int i = 0; i < 9; ++i)
		used += 'a';
	for (int i = 0; i < n - k + 1; ++i) {
		cin >> s;
		if (i == 0) {
			if (s == "YES") {
				for (int j = 0; j < k; ++j)
					ans[j] = nxt();
			} else {
				ans[0] = ans[1] = nxt();
				for (int j = 2; j < k; ++j)
					ans[j] = nxt();
			}
		} else {
			if (s == "YES")
				ans[i + k - 1] = nxt();
			else
				ans[i + k - 1] = ans[i];
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	return 0;
}