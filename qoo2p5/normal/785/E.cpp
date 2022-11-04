#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;

#define sz(x) (int) (x).size()

void run();

signed main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

const int N = (int) 2e5 + 123;
const int LEN = (int) sqrt(N * log2(N));
const int CNT = N / LEN + 2;

int n, q;
int a[N];
int w[CNT][LEN + 1];

void reorder(int pos, int val) {
	int bl = pos / LEN;
	int pp = -1;
	
	for (int i = 0; i < LEN; i++) {
		if (w[bl][i] == a[pos]) {
			pp = i;
		}
	}
	
	assert(pp != -1);
	a[pos] = val;
	pos = pp;
	w[bl][pos] = val;
	
	while (pos > 0 && w[bl][pos - 1] > w[bl][pos]) {
		swap(w[bl][pos - 1], w[bl][pos]);
		pos--;
	}
	while (w[bl][pos + 1] < w[bl][pos]) {
		swap(w[bl][pos + 1], w[bl][pos]);
		pos++;
	}
}

int calc(int pos) {
	int ans = 0;
	int bl = pos / LEN;
	for (int i = 0; i < bl; i++) {
		ans += LEN - (int) (upper_bound(w[i], w[i] + LEN + 1, a[pos]) - w[i]);
	}
	for (int j = bl * LEN; j < pos; j++) {
		ans += (a[j] > a[pos]);
	}
	
	int tmp = a[pos] - (pos - ans);
	return ans + tmp;
}

void run() {
	for (int i = 0; i < CNT; i++) {
		fill(w[i], w[i] + LEN + 1, INF);
	}
	
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		a[i] = i;
		w[i / LEN][i % LEN] = a[i];
	}
	
	ll cur = 0;
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		if (l == r) {
			cout << cur << "\n";
			continue;
		}
		if (l > r) swap(l, r);
		
		cur -= calc(l);
		cur -= calc(r);
		
		int x = a[l];
		int y = a[r];
		
		if (x > y) {
			cur++;
		}
		
		if (l / LEN == r / LEN) {
			swap(a[l], a[r]);
		} else {
			reorder(l, y);
			reorder(r, x);
		}
		
		cur += calc(l);
		cur += calc(r);
		if (y > x) {
			cur--;
		}
		cout << cur << "\n";
	}
}