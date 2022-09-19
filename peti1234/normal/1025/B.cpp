#include <bits/stdc++.h>

using namespace std;

long long n, x, y, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++) {
        cin >> x >> y;
        ans=__gcd(ans, x*y);
	}
	if (ans==1) {
        cout << -1 << "\n";
        return 0;
	}
	x=__gcd(ans, x), y=__gcd(ans, y);
	for (int i=2; i<=1e5; i++) {
        if (x%i==0 || y%i==0) {
            cout << i << "\n";
            return 0;
        }
	}
	cout << max(x, y) << "\n";
    return 0;
}