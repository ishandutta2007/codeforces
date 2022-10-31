#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void one_case() {
	int n;
	int m;
	int x;
	cin >> n >> m >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> r(n);
	priority_queue<pair<int, int>> heap;
	for (int i = 0; i < m; ++i) {
		heap.push(make_pair(0, i));
	}
	for (int i = 0; i < n; ++i) {
		auto t = heap.top();
		heap.pop();
		r[i] = t.second;
		t.first -= a[i];
		heap.push(t);
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", r[i] + 1);
	}
	printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}