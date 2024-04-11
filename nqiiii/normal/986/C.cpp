#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[(1 << 22) + 10];
bool b[1 << 22], c[1 << 22];
queue<int> q;

void upd(int p) {
	if (!b[p]) {
		b[p] = 1; q.push(p);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]); c[a[i]] = 1;
	}
	for (int i = 1; i <= m; ++i)
		if (!b[a[i]]) {
			++ans; q.push(a[i]); b[a[i]] = 1;
			while (!q.empty()) {
				int p = q.front(); q.pop();
				for (int i = 0; i < n; ++i)
					if (p >> i & 1) upd(p ^ (1 << i));
				if (c[p]) upd(((1 << n) - 1) ^ p);
			}
		}
	printf("%d", ans);
}