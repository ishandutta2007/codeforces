#include <iostream>

using namespace std;

typedef long long ll;

int a[202020];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll r = 0;
        for (int i = 1; i <= n; i++) {
            int u = max(a[i],a[i-1]);
            if (i == n) {
                r += u-a[i];
            } else if (a[i+1] > a[i]) {
                r += min(u-a[i],a[i+1]-a[i]);
            }
            a[i] = u;
        }
        cout << r << "\n";
    }
}