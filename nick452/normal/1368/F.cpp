#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int l = 1;
	int mr = 0;
	for (int i = 2; i < n; ++i) {
		int c = (n + i - 1) / i;
		int r = n - c - (i - 1);
		if (r > mr) {
			mr = r;
			l = i;
		}
	}
	if (mr == 0) {
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		if (i % l != 0) {
			t[i] = 1;
		}
	}
	vector<int> a(n);
	while (1) {
		vector<int> p;
		for (int i = 0; i < l; i++) {
			for (int k = i; k < n; k += l) {
				if (k < n && a[k] == 0 && t[k] == 1 && p.size() < l) {
					a[k] = 1;
					p.push_back(k);
				}
			}
		}
		printf("%d", (int)p.size());
		for (int i : p) printf(" %d", i + 1);
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (a == t) {
			printf("0\n");
			fflush(stdout);
			return 0;
		}
		--x;
		for (int i = 0; i < p.size(); i++) a[(x + i) % n] = 0;
	}
	return 0;
}