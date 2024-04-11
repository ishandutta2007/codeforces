#include <iostream>

using namespace std;

typedef long long ll;

int n, k;
int c[101010];
int u[101010];
ll w, z;
ll t;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		w += c[i];
	}
	c[0] = c[n];
	c[n+1] = c[1];
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		u[x] = 1;
		z += c[x];
	}
	u[0] = u[n];
	u[n+1] = u[1];
	for (int i = 1; i <= n; i++) {
		if (u[i]) {
			t += (w-c[i])*c[i];
		} else {
			t += z*c[i];
			if (!u[i-1]) t += c[i-1]*c[i];
			if (!u[i+1]) t += c[i+1]*c[i];
		}
	}
	cout << t/2 << "\n";
}