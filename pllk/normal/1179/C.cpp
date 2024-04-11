#include <iostream>

using namespace std;

typedef long long ll;

#define N (1<<20)
#define Z 1000000
#define INF 999999999

ll p[2*N][2];

void set(int k, ll x) {
	k += N;
	p[k][0] = x;
	p[k][1] = x;
	for (k /= 2; k >= 1; k /= 2) {
		p[k][0] = p[2*k][0]+p[2*k+1][0];
		p[k][1] = min(p[2*k][1]+p[2*k+1][0],p[2*k+1][1]);
	}
}

int answer() {
	if (p[1][1] >= 0) return -1;
	int k = 1;
	int b = 0;
	while (k < N) {
		if (p[2*k+1][1]+b < 0) k = 2*k+1;
		else {b += p[2*k+1][0]; k = 2*k;}
	}
	return k-N;
}

int n, m, q;
int a[303030];
int b[303030];
int c[1222333];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]--;
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		c[b[i]]++;
	}
	for (int i = 0; i <= Z; i++) {
		set(i,c[i]);
	}
	cin >> q;
	for (int k = 1; k <= q; k++) {
		int t, i, x;
		cin >> t >> i >> x;
		if (t == 1) {
			c[a[i]]++;
			set(a[i],c[a[i]]);
			a[i] = x;
			c[a[i]]--;
			set(a[i],c[a[i]]);
		} else {
			c[b[i]]--;
			set(b[i],c[b[i]]);
			b[i] = x;
			c[b[i]]++;
			set(b[i],c[b[i]]);
		}
		cout << answer() << "\n";
	}
}