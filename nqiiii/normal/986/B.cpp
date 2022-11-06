#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c[1000010];
ll ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		for (int j = n + 1 - x; j; j -= j & -j) ans += c[j];
		for (int j = n + 1 - x; j <= n; j += j & -j) ++c[j];
	}
	printf("%s", (n % 2) ^ (ans % 2) ? "Um_nik" : "Petr");
}