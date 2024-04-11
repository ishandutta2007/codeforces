#include <bits/stdc++.h>
using namespace std;

int a[100010];
vector <int> all;
set <int> S;
vector <int> st;

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!all.size() || abs(all.back()) != a[i]) all.push_back(a[i]);
	}
	int ans = 0, A = -1, B = -1, lst = -1;
	for (int i = 0; i < all.size(); i++) {
		int x = all[i];
		if (A == x) {
			if (lst != -1) B = lst, S.clear(), lst = -1;
		} else if (B == x) {
			if (lst != -1) A = lst, S.clear(), lst = -1;
		} else if (S.count(x)) {
			assert(lst != x), A = x, B = lst, S.clear(), lst = -1;
		} else S.insert(x), ans++, lst = x;
	}
	printf("%d\n", ans);
	return 0;
}