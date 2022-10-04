#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

set<int> tmp;
vector<pii> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	int sv = 0;
	for (int i = 0; i < n; i++) {
		int x; ni(x);
		if (tmp.find(x) != tmp.end()) {
			ans.push_back(mp(sv, i));
			sv = i + 1;
			tmp.clear();
		}
		else {
			tmp.insert(x);
		}
	}
	if (ans.empty()) {
		puts("-1"); return 0;
	}
	int sz = ans.size();
	ans[sz - 1].second = n - 1;
	printf("%d\n", sz);
	for (auto &x : ans) {
		printf("%d %d\n", x.first + 1, x.second + 1);
	}
	return 0;
}