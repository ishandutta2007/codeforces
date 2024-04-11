#include <iostream>

using namespace std;

int n;
int a[303030];
int fi[303030];
int la[303030];
int gg[303030];
int hh[303030];

#define N (1<<19)

int pp[2*N];

void setVal(int k, int x) {
	k += N;
	pp[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		pp[k] = max(pp[2*k],pp[2*k+1]);
	}
}

int getMax(int a, int b) {
	a += N; b += N;
	int u = 0;
	while (a <= b) {
		if (a%2 == 1) u = max(u,pp[a++]);
		if (b%2 == 0) u = max(u,pp[b--]);
		a /= 2; b /= 2;
	}
	return u;
}

void lol() {
	cin >> n;
	for (int i = 1; i <= n; i++) fi[i] = la[i] = 0;
	int z = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (fi[a[i]] == 0) {
			fi[a[i]] = i;
			z++;
		}
		la[a[i]] = i;
	}
	int h = 0;
	for (int i = 1; i <= n; i++) {
		if (fi[i]) {
			hh[i] = h;
			h = i;
		}
	}
	for (int i = 1; i <= n; i++) setVal(i,0);
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (fi[a[i]] == i) {
			int g = getMax(hh[a[i]],hh[a[i]])+1;
			p = max(p,g);
			gg[a[i]] = g;
		}
		if (la[a[i]] == i) {
			setVal(a[i],gg[a[i]]);
		}
	}
	cout << z-p << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) lol();
}