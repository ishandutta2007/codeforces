#include <iostream>

using namespace std;

typedef long long ll;

ll a[202020];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int j = 1; j <= k; j++) {
            ll s = a[1];
            for (int i = 2; i <= n; i++) s = max(s,a[i]);
            for (int i = 1; i <= n; i++) a[i] = s-a[i];
            if (j >= 4 && j%2 == k%2) break;
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}