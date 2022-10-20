#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int b[N], cnt, c[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1, greater<int>());
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt == 0 || a[i] != b[cnt]) {
			cnt++;
			b[cnt] = a[i];
		}
		c[cnt]++;
	}
	for (int i = 1; i <= cnt; i++) {
		if (c[i] % 2 != 0) {
			puts("Conan");
			return 0;
		}
	}
	puts("Agasa");
	return 0;
}