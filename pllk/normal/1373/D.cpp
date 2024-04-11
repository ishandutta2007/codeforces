#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[202020];
ll sa[202020], sb[202020];
ll ss[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll ma = 0, mb = 0;
		ll r = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ss[n] = 0;
		for (int i = n-1; i >= 0; i--) {
			ss[i] = ss[i+1];
			if (i%2 == 0) ss[i] += a[i];
		}
		for (int i = 0; i < n; i++) {
			sa[i] = sb[i] = 0;
			if (i > 0) {
				sa[i] += sa[i-1];
				sb[i] += sb[i-1];
			}
			if (i%2 == 0) {
				sa[i] += a[i];
				r = max(r,sa[i]);
				r = max(r,sa[i]+sb[i]-sa[i]+ma+ss[i+1]);
				ma = max(ma,sa[i]-sb[i]);
			} else {
				sb[i] += a[i];
				r = max(r,sa[i]);
				r = max(r,sa[i]+sb[i]-sa[i]+mb+ss[i+1]);
				mb = max(mb,sa[i]-sb[i]);
			}
		}
		cout << r << "\n";
	}
}