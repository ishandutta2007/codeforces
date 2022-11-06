#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
bool vis[123321];

void f__k(int v) {
	for (int i = ans; i >= 1; --i)
		if (v - i >= 0) {
			vis[i] = 1; v -= i;
		}
}

void output(int d) {
	int cnt = 0;
	for (int i = 1; i <= ans; ++i)
		if (vis[i] == d) ++cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= ans; ++i)
		if (vis[i] == d) printf("%d ", i);
	printf("\n");
}

int main() {
	scanf("%d%d", &a, &b);
	for (int i = 1; 1ll * i * (i + 1) / 2 <= (a + b); ++i) {
		ans = i;
	}
	if (a < b) {
		f__k(a);
		output(1); output(0);
	} else {
		f__k(b);
		output(0); output(1);
	}
}