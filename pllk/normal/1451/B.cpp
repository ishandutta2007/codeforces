#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            bool f = false;
            for (int j = l-1; j >= 0; j--) {
                if (s[j] == s[l]) f = true;
            }
            for (int j = r+1; j < n; j++) {
                if (s[j] == s[r]) f = true;
            }
            if (f) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}