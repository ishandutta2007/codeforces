#include <iostream>

using namespace std;

typedef long long ll;

void print(ll n, ll l, ll r, int a) {
	//cout << " [" << n << " " << l << " " << r << " " << a << "] ";
	if (l > r) return;
	while (l <= min(2*n-2,r)) {
		if (l%2 == 1) cout << 1+a << " ";
		else cout << l/2+1+a << " ";
		l++;
	}
	if (l > r) return;
	int f = 0;
	if (r == n*(n-1)+1) {f = 1; r--;}
	print(n-1,l-(2*n-2),r-(2*n-2),a+1);
	if (f) cout << 1+a << " ";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll l, r;
		cin >> n >> l >> r;
		print(n,l,r,0);
		cout << "\n";
	}
}