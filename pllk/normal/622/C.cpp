#include <iostream>

using namespace std;

int n, m;
int a[202020];
int d[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d[n] = -1;
    for (int i = n-1; i >= 1; i--) {
        if (a[i] != a[i+1]) d[i] = i+1;
        else d[i] = d[i+1];
    }
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        if (a[l] != x) {
            cout << l << "\n";
        } else {
            if (d[l] == -1 || d[l] > r) cout << -1 << "\n";
            else cout << d[l] << "\n";
        }
    }
}