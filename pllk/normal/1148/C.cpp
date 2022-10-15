#include <iostream>
#include <vector>

using namespace std;

int n;
int p[303030];
int u[303030];
vector<pair<int,int>> v;

bool ok(int a, int b) {
	return 2*abs(a-b) >= n;
}

void lol(int a, int b) {
	if (!ok(a,b)) return;
	v.push_back({a,b});
	swap(p[a],p[b]);
	u[p[a]] = a;
	u[p[b]] = b;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		u[p[i]] = i;
	}
	for (int i = 2; i <= n-1; i++) {
		int k = u[i];
		if (ok(i,k)) {
			lol(i,k);
		} else if (ok(k,n) && ok(n,i)) {
			lol(k,n); lol(n,i);
		} else if (ok(k,1) && ok(1,i)) {
			lol(k,1); lol(1,i);
		} else if (ok(k,n) && ok(1,n) && ok(1,i)) {
			lol(k,n); lol(1,n); lol(1,i);
		} else if (ok(k,1) && ok(1,n) && ok(n,i)) {
			lol(k,1); lol(1,n); lol(n,i);
		}
	}
	if (p[1] != 1) lol(1,n);
	cout << v.size() << "\n";
	for (auto x : v) {
		cout << x.first << " " << x.second << "\n";
	}
}