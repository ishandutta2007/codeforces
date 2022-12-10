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

const int maxn = 2e5 + 10;
LL sum[maxn];
int x[maxn];
int n, m;

inline void add(int l, int r, LL val) {
	sum[l] += val;
	sum[r] -= val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> x[i], x[i]--;
	for (int i = 0; i + 1 < m; i++) {
		int fi = x[i],
		se = x[i + 1];
		if (fi > se)
			swap(fi, se);
		if (fi == se)
			continue;
		add(0, fi, se - fi);
		add(se + 1, n, se - fi);
		add(fi + 1, se, se - fi - 1);
		add(fi, fi + 1, se);
		add(se, se + 1, fi + 1);
	}
	for (int i = 0; i < n; i++)
		sum[i + 1] += sum[i];
	for (int i = 0; i < n; i++)
		cout << sum[i] << ' ';
	cout << endl;
	return 0;
}