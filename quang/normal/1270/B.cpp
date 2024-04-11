#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int found = 0;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i + 1]) >= 2) {
                cout << "YES\n";
                cout << i << ' ' << i + 1 << '\n';
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "NO\n";
        }
    }   
    return 0;
}