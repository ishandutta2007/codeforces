#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;

    if (n%2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 1;
    for (int i=0; i<n/2; ++i) {
        ans *= 2;
    }
	
    cout << ans << '\n';
	return 0;
}