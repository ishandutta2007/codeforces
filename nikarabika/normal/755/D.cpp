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

const int maxn = 2e6 + 10;

struct {
	int fen[maxn];

	void inc(int idx) {
		for (idx++; idx < maxn; idx += idx & -idx)
			fen[idx]++;
	}

	int get(int idx) {
		int sum = 0;
		for (; idx; idx -= idx & -idx)
			sum += fen[idx];
		return sum;
	}

	int get(int st, int en) {
		return get(en) - get(st);
	}
} fen, nef;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	smin(k, n - k);
	LL cur = 1;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		int nxt = (pos + k) % n;
		cur += 1 + fen.get(pos + 1, pos + k) + nef.get(pos + 1, pos + k);
		fen.inc(pos);
		fen.inc(pos + n);
		nef.inc(nxt);
		nef.inc(nxt + n);
		pos = nxt;
		cout << cur << ' ';
	}
	cout << '\n';
	return 0;
}