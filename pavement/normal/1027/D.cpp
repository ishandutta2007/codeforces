#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int N, T, C[200005], A[200005], link[200005], sz[200005];
bool V[200005];

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
	for (int i = 1; i <= N; i++) link[i] = i, sz[i] = 1;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N; i++) cin >> A[i], unite(i, A[i]);
	for (int i = 1; i <= N; i++)
		if (!V[find(i)]) {
			int h = i, t = i, m = 1e9;
			do {
				h = A[A[h]];
				t = A[t];
			} while (h != t);
			do {
				m = min(m, C[t]);
				t = A[t];
			} while (t != h);
			T += m;
			V[find(i)] = 1;
		}
	cout << T << '\n';
}