#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll s = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s += x;
        }
        if (s == m) cout << "YES\n";
        else cout << "NO\n";
    }
}