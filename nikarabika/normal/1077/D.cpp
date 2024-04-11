//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	const int m = 2e5 + 10;
	pii cnt[m];
	int n, k;
	for (int i = 0; i < m; i++)
		cnt[i].R = i;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x, x--;
		cnt[x].L++;
	}
	sort(cnt, cnt + m, greater<pii>());
	int lo = 1, hi = n + 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		int cur = 0;
		for (int i = 0; i < m; i++)
			cur += cnt[i].L / mid;
		if (cur >= k)
			lo = mid;
		else
			hi = mid;
	}
	int ptr = 0;
	for (int i = 0; i < k; i++) {
		while (cnt[ptr].L < lo)
			ptr++;
		cout << cnt[ptr].R + 1 << ' ';
		cnt[ptr].L -= lo;
	}
	return 0;
}