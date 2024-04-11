#include <iostream>

using namespace std;

int p[1111];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];
        int ok = 0;
        for (int b = 1; b <= n; b++) {
            int a = 0;
            for (int i = 1; i < b; i++) if (p[i] < p[b]) a = i;
            int c = 0;
            for (int i = b+1; i <= n; i++) if (p[i] < p[b]) c = i;
            if (a && c) {
                cout << "YES\n";
                cout << a << " " << b << " " << c << "\n";
                ok = 1;
                break;
            }
        }
        if (!ok) cout << "NO\n";
    }
}