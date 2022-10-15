#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int w[n];
        for (int i = 0; i < n; i++) cin >> w[i];
        int s = 0;
        bool f = false;
        for (int i = 0; i < n; i++) {
            s += w[i];
            if (s == x) {
                if (i != n-1) swap(w[i],w[i+1]);
                else f = true;
            }
        }
        if (f) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << w[i] << " ";
            cout << "\n";
        }
    }
}