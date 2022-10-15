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
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);
        int b[n] = {0};
        for (int i = 0; i < n; i++) {
            if (i != 0 && a[i-1] == a[i]) continue;
            cout << a[i] << " ";
            b[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (!b[i]) cout << a[i] << " ";
        }
        cout << "\n";
    }
}