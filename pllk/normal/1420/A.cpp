#include <iostream>

using namespace std;

int a[101010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        bool ok = false;
        for (int i = 1; i <= n-1; i++) {
            if (a[i] <= a[i+1]) ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}