#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

unordered_set<long long> s;

void doall() {
	s.clear();
	for (long long i = 1;; ++i) {
		long long j = i * i * 2;
		if (j > 2e9) {
			break;
		}
		s.insert(j);
	}
	for (long long i = 1;; ++i) {
		long long j = i * i * 4;
		if (j > 2e9) {
			break;
		}
		s.insert(j);
	}
}

int doit(long long n) {
	return s.count(n);
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	doall();
	while (t--) {
		int n;
		cin >> n;
		if (doit(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}