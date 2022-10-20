#include <bits/stdc++.h>

using namespace std;

const int MAX = 15000010;
const int N = 300010;

int n;
int a[N];
int cnt[MAX];
int prime[MAX];

int main() {
	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i; j < MAX; j += i) {
				prime[j] = i;
			}
		}
	}
	scanf("%d", &n);
	int foo = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		foo = __gcd(foo, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= foo;
		while (a[i] > 1) {
			int u = prime[a[i]];
			while (a[i] % u == 0) {
				a[i] /= u;
			}
			cnt[u]++;
		}
	}

	int res = 0;
	for (int i = 1; i < MAX; i++) {
		res = max(res, cnt[i]);
	}
	cout << (res ? n - res : -1) << endl;
	return 0;
}