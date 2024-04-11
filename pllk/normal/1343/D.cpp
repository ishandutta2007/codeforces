#include <iostream>

using namespace std;

int n, k;
int a[202020];
int b[404040];
int c[404040];

void lol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= 2*k+1; i++) b[i] = c[i] = 0;
	for (int i = 1; i <= n/2; i++) {
		int x = a[i];
		int y = a[n-i+1];
		b[x+y]++;
		c[1+min(x,y)]++;
		c[k+max(x,y)+1]--;
	}
	for (int i = 1; i <= 2*k+1; i++) {
		c[i] = c[i-1]+c[i];
	}
	int p = n;
	for (int i = 2; i <= 2*k; i++) {
		int u = n/2;
		int d = 0;
		u -= b[i];
		d += c[i]-b[i];
		u -= c[i]-b[i];
		d += 2*u;
		p = min(p,d);
	}
	cout << p << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}