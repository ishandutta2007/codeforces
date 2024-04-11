#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n+1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll d = 0;
        for (int i = 1; i <= n-1; i++) {
            d += abs(a[i]-a[i+1]);
        }
        ll r = d;
        for (int i = 1; i <= n; i++) {
            ll e = d;
            if (i == 1) {
                e -= abs(a[1]-a[2]);
            } else if (i == n) {
                e -= abs(a[n-1]-a[n]);
            } else {
                e -= abs(a[i-1]-a[i]);
                e -= abs(a[i]-a[i+1]);
                e += abs(a[i-1]-a[i+1]);
            }
            r = min(r,e);
        }
        cout << r << "\n";
    }
}