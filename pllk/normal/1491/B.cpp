#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        cin >> n >> u >> v;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int m = 0;
        for (int i = 0; i < n-1; i++) {
            m = max(m,abs(a[i+1]-a[i]));
        }
        if (m == 0) {
            cout << v+min(u,v) << "\n";
        } else if (m == 1) {
            cout << min(u,v) << "\n";
        } else {
            cout << "0\n";
        }
    }
}