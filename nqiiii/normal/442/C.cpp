#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
int n, a[maxn + 10];
int id[maxn + 10], delta;
long long ans;
set<int> st;

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		st.insert(i);
		scanf("%d", &a[i]); id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i < n; ++i) {
		int p = id[i];
		if (*st.begin() == p || *--st.end() == p) {
			ans += ll(a[p] - delta) * ((int)st.size() - 2); st.erase(p);
			delta = a[p];
		} else {
			auto it = st.lower_bound(p), it2 = it;
			int w1 = *++it;
			int w2 = *--it2;
			ans += min(a[w1], a[w2]) - delta;
			st.erase(p);
		}
	}
	printf("%lld", ans);
}