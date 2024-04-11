#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, t, P[200005], inv[200005], link[200005], sz[200005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i], inv[P[i]] = i, link[i] = i, sz[i] = 1;
	for (int i = 1; i <= N; i++) {
		if (inv[i] ^ 1 && P[inv[i] - 1] < i && inv[i] ^ N && P[inv[i] + 1] < i) {
			if (sz[find(inv[i] - 1)] > sz[find(inv[i] + 1)]) {
				for (int j = inv[i] + 1; j <= inv[i] + sz[find(inv[i] + 1)]; j++) {
					if (P[j] > i) continue;
					if (inv[i - P[j]] >= inv[i] - sz[find(inv[i] - 1)] && inv[i - P[j]] < inv[i]) t++;
				}
			} else {
				for (int j = inv[i] - 1; j >= inv[i] - sz[find(inv[i] - 1)]; j--) {
					if (P[j] > i) continue;
					if (inv[i - P[j]] > inv[i] && inv[i - P[j]] <= inv[i] + sz[find(inv[i] + 1)]) t++;
				}
			}
			unite(inv[i], inv[i] - 1);
			unite(inv[i], inv[i] + 1);
		} else if (inv[i] ^ 1 && P[inv[i] - 1] < i) {
			unite(inv[i], inv[i] - 1);
		} else if (inv[i] ^ N && P[inv[i] + 1] < i) {
			unite(inv[i], inv[i] + 1);
		}
	}
	cout << t << '\n';
}