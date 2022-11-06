#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 100000;
int n, k1, k2, a[maxN + 10], b[maxN + 10];
Long ans;

struct Node {
	int id, v;
	bool operator < (const Node &t) const {
		return v < t.v;	
	}
};
priority_queue<Node> heap;

int main() {
	scanf("%d%d%d", &n, &k1, &k2);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i) {
		a[i] -= b[i]; heap.push((Node){i, abs(a[i])});
		ans += 1ll * a[i] * a[i];
	}
	for (int i = 1; i <= k1 + k2; ++i) {
		Node p = heap.top(); heap.pop();
		ans -= 1ll * p.v * p.v - 1ll * (p.v - 1) * (p.v - 1);
		heap.push((Node){p.id, abs(p.v - 1)});
	}
	printf("%lld", ans);
}