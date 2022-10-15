#include <iostream>

using namespace std;

#define N (1<<20)

int p[2*N];

void inc(int k, int x) {
	k += N;
	p[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		p[k] = p[2*k]+p[2*k+1];
	}
}

int find(int c) {
	int k = 1;
	while (k < N) {
		if (p[2*k] >= c) {
			k = 2*k;
		} else {
			c -= p[2*k];
			k = 2*k+1;
		}
	}
	return k-N;
}

int n, q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		inc(x,1);
	}
	for (int i = 1; i <= q; i++) {
		int x;
		cin >> x;
		if (x > 0) inc(x,1);
		else {
			int u = find(-x);
			inc(u,-1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (p[N+i]) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}