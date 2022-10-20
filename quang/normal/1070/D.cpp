#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int64_t INF = 1e16;

pair<int64_t, int64_t> f[N];
int a[N];
int n, k;

template<class T> void minimize(T &a, T b) {
	if (a > b) a = b;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) f[i] = {INF, INF};
	for (int i = 0; i < n; ++i) {
		int64_t cur = a[i + 1] + f[i].second;
		//cerr << i << ' ' << f[i].first << ' ' << f[i].second << ' ' << cur << endl;
		minimize(f[i + 1], make_pair(f[i].first + cur / k + !!(cur % k), int64_t(0)));
		if (cur % k <= a[i + 1]) minimize(f[i + 1], make_pair(f[i].first + cur / k, cur % k));
	}
	cout << (f[n].first + bool(f[n].second)) << endl;
	return 0;
}