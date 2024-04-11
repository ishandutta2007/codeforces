#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[55];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i]-a[i-1] > 1) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}