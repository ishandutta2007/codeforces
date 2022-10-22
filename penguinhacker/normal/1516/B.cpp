#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int xo=0;
		for (int& i : a) {
			cin >> i;
			xo^=i;
		}
		if (xo==0) {
			int xo2=0;
			bool ok=0;
			for (int i=0; i<n-1; ++i) {
				xo2^=a[i], xo^=a[i];
				if (xo==xo2) {
					ok=1;
					break;
				}
			}
			cout << (ok?"YES":"NO") << "\n";
		} else {
			int c=0, cx=0;
			for (int i : a) {
				cx^=i;
				if (cx==xo) {
					++c;
					cx=0;
				}
			}
			cout << (c>1?"YES":"NO") << "\n";
		}
	}
	return 0;
}