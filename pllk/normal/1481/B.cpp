#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int h[n+1];
        for (int i = 1; i <= n; i++) cin >> h[i];
        int r = 0;
        for (int i = 1; i <= k; i++) {
            int p = 1;
            while (true) {
                r = p;
                if (p == n) break;
                if (h[p] >= h[p+1]) p += 1;
                else {h[p]++; break;}
            }
            if (r == n) break;
        }
        if (r == n) cout << -1 << "\n";
        else cout << r << "\n";
    }
}