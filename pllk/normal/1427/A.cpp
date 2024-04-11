#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s == 0) {
            cout << "NO\n";
            continue;
        }
        sort(a,a+n);
        if (s > 0) {
            reverse(a,a+n);
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}