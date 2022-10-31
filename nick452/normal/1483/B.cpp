#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void one_case()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> next(n);
	for (int i = 0; i < n; ++i) {
		next[i] = (i + 1) % n;
	}
	vector<int> result;
	set<int> positions;
	for (int i = 0; i < n; ++i) {
		if (gcd(a[i], a[next[i]]) == 1) {
			positions.insert(i);
		}
	}
	int last_delete_idx = -1;
	while (!positions.empty()) {
		auto it = positions.upper_bound(last_delete_idx);
		if (it == positions.end()) {
			it = positions.begin();
		}
		int p = *it;
		result.push_back(next[p]);
		if (p == next[p]) {
			break;
		}
		positions.erase(p);
		positions.erase(next[p]);
		last_delete_idx = next[p];
		next[p] = next[last_delete_idx];
		if (gcd(a[p], a[next[p]]) == 1) {
			positions.insert(p);
		}
	}
	printf("%d", result.size());
	for (int x : result) {
		printf(" %d", x + 1);
	}
	printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}