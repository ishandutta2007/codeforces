#include <bits/stdc++.h>

using namespace std;

void solve(int first, int last, vector<int> count) {
	if (!count[first] || !count[last]) {
		return;
	}
	int n1 = first;
	int n2 = last;
	for (int k = 0; k < 4; ++k) {
		if (count[k]) {
			n1 = min(n1, k);
			n2 = max(n2, k);
		}
	}
	vector<int> results;

	auto add = [&](int at) -> bool {
		if (count[at]) {
			--count[at];
			results.push_back(at);
			return true;
		}
		return false;
	};
	for (int k = first; k >= n1; --k) {
		if (!add(k)) {
			return;
		}
	}
	for (int k = n1; k < last; ++k) {
		while (count[k]) {
			if (!add(k + 1)) {
				return;
			}
			if (!add(k)) {
				return;
			}
		}
		if (!add(k + 1)) {
			return;
		}
	}
	for (int k = last + 1; k <= n2; ++k) {
		if (!add(k)) {
			return;
		}
	}
	for (int k = n2; k > last; --k) {
		while (count[k]) {
			if (!add(k - 1)) {
				return;
			}
			if (!add(k)) {
				return;
			}
		}
		if (!add(k - 1)) {
			return;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (count[i]) {
			return;
		}
	}
	printf("YES\n");
	for (int i = 0; i < results.size(); ++i) {
		printf("%d ", results[i]);
	}
	printf("\n");
	exit(0);
}

int main()
{
	std::ios::sync_with_stdio(false);
	vector<int> count(4);
	for (int i = 0; i < 4; ++i) {
		cin >> count[i];
	}
	for (int first = 0; first < 4; ++first) {
		for (int last = 0; last < 4; ++last) {
			solve(first, last, count);
		}
	}
	printf("NO\n");
	return 0;
}