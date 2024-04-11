#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        lint sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        lint mx = 0;
        lint s = 0;
        for (int i = 0; i < n - 1; i++) {
            s += a[i];
            mx = max(mx, s);
            if (s < 0) {
                s = 0;
            }
        }
        s = 0;
        for (int i = 1; i < n; i++) {
            s += a[i];
            mx = max(mx, s);
            if (s < 0) {
                s = 0;
            }
        }
        
        if (sum > mx) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}