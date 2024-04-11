#include <iostream>

using namespace std;

typedef long long ll;

int n, m, l;
ll a[101010];
int c;

int main() {
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i-1] <= l && a[i] > l) c++;
	}
	for (int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << c << "\n";
		} else {
			int p, d;
			cin >> p >> d;
			if (a[p] <= l && a[p]+d > l) {
				if (a[p-1] <= l && a[p+1] <= l) c++;
				if (a[p-1] > l && a[p+1] > l) c--;
			}
			a[p] += d;
		}
	}
}