#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int a[202020];
int w[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= k; i++) cin >> w[i];
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		sort(w+1,w+k+1);
		ll r = 0;
		int u = k+1;
		int j = 1;
		for (int i = 1; i <= k; i++) {
			if (w[i] == 1) {
				r += 2*a[j++];
			} else if (w[i] == 2) {
				r += a[j++];
				r += a[j++];
			} else {
				r += a[j++];
				w[i]--;
				if (u == k+1) u = i;
			}
		}
		for (int i = u; i <= k; i++) {
			while (w[i] > 1) {
				w[i]--; j++;
			}
			r += a[j++];
		}
		cout << r << "\n";
	}
}