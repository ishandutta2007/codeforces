#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int p[202020];
int x, a;
int y, b;
ll k;

bool ok(int t) {
	int u = n-1;
	ll h = 0;
	for (int i = 0; i < t; i++) {
		if ((i+1)%a == 0 && (i+1)%b == 0) {
			h += (p[u]/100*(x+y));
			if (h >= k) return true;
			u--;
		}
	}
	for (int i = 0; i < t; i++) {
		if ((i+1)%a == 0 && (i+1)%b == 0) continue;
		if ((i+1)%b == 0) {
			h += (p[u]/100*y);
			if (h >= k) return true;
			u--;
		}
	}
	for (int i = 0; i < t; i++) {
		if ((i+1)%a == 0 && (i+1)%b == 0) continue;
		if ((i+1)%a == 0) {
			h += (p[u]/100*x);
			if (h >= k) return true;
			u--;
		}
	}
	return false;
}

void lol() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p,p+n);
	cin >> x >> a;
	cin >> y >> b;
	if (x > y) {
		swap(x,y);
		swap(a,b);
	}
	cin >> k;
	if (!ok(n)) {
		cout << "-1\n";
		return;
	}
	int u = 0;
	for (int b = n; b >= 1; b /= 2) {
		while (u+b <= n && !ok(u+b)) u += b;
	}
	cout << u+1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) lol();
}