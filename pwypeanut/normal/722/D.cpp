#include <bits/stdc++.h>
using namespace std;

int N;
long long a[1000005];
set<int> S;

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < N; i++) S.insert(a[i]);
	while (true) {
		int x = *S.rbegin();
		S.erase(--S.end());
		int newx = x;
		x >>= 1;
		bool fail = 0;
		while (true) {
			if (x == 0) {
				fail = 1;
				break;
			}
			if (S.find(x) == S.end()) {
				S.insert(x);
				break;
			} else x >>= 1;
		}
		if (fail) {
			printf("%d ", newx);
			for (set<int>::iterator it = S.begin(); it != S.end(); it++) printf("%d ", *it);
			printf("\n");
			return 0;
		}
	}
}