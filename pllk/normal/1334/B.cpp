#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int a[101010];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll x;
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a,a+n);
		reverse(a,a+n);
		ll s = 0;
		int c = 0;
		for (int i = 0; i < n; i++) {
			s += a[i];
			if ((i+1)*x <= s) c++;
			else break;
		}
		cout << c << "\n";
	}
}