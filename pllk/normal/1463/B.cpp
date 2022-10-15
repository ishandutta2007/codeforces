#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n+1];
        ll s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (i%2 == 1) s1 += x[i];
            else s2 += x[i];
        }
        if (s1 < s2) {
            for (int i = 1; i <= n; i++) {
                if (i%2 == 1) cout << 1 << " ";
                else cout << x[i] << " ";
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i%2 == 0) cout << 1 << " ";
                else cout << x[i] << " ";
            }
        }
        cout << "\n";
    }
}