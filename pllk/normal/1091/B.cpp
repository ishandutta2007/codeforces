#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

int n;
int x[1111], y[1111];
int a[1111], b[1111];
set<pair<int,int>> s;

void check(int tx, int ty) {
	for (int i = 1; i <= n; i++) {
		int ux = tx-x[i];
		int uy = ty-y[i];
		if (!s.count({ux,uy})) return;
	}
	cout << tx << " " << ty << "\n";
	exit(0);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		s.insert({a[i],b[i]});
	}
	for (int i = 1; i <= n; i++) {
		check(x[1]+a[i],y[1]+b[i]);
	}
}