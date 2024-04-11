#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int n, m;
int c[555];
ll z = 1;

int vv[555][555];
ll dd[555][555];

ll calc(int a, int b) {
	if (a >= b) return 1;
	if (vv[a][b]) return dd[a][b];
	int pi = a;
	for (int i = a; i <= b; i++) {
		if (c[i] < c[pi]) pi = i;
	}
	ll d1 = 0;
	for (int i = a-1; i < pi; i++) {
		d1 += calc(a,i)*calc(i+1,pi-1);
		d1 %= M;
	}
	ll d2 = 0;
	for (int i = pi; i <= b; i++) {
		d2 += calc(pi+1,i)*calc(i+1,b);
		d2 %= M;
	}
	vv[a][b] = 1;
	dd[a][b] = d1*d2%M;
	return dd[a][b];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << calc(1,n) << "\n";
}