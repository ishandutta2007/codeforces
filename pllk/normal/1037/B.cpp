#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, s;
int a[202020];
ll u;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int k = (n+1)/2;
	u += abs(a[k]-s);
	a[k] = s;
	for (int i = k+1; i <= n; i++) {
		if (a[i] < a[i-1]) {
			u += abs(a[i]-a[i-1]);
			a[i] = a[i-1];
		}
	}
	for (int i = k-1; i >= 1; i--) {
		if (a[i] > a[i+1]) {
			u += abs(a[i]-a[i+1]);
			a[i] = a[i+1];
		}
	}
	cout << u << "\n";
}