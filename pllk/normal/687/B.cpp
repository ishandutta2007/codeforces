#include <iostream>

using namespace std;

int n, k;
int c[1010101];
int a[1010101];

int t[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 1000000; i++) {
        if (a[i]) continue;
        for (int j = i; j <= 1000000; j += i) {
            if (a[j] == 0) a[j] = i;
        }
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    while (k > 1) {
        int u = a[k];
        int c = 0;
        while (a[k] == u) {
            k /= u;
            c++;
        }
        t[u] = c;
    }
    for (int i = 1; i <= n; i++) {
        int k = c[i];
        while (k > 1) {
            int u = a[k];
            int c = 0;
            while (a[k] == u) {
                k /= u;
                c++;
            }
            if (t[u] <= c) t[u] = 0;
        }
    }
    bool ok = true;
    for (int i = 1; i <= 1000000; i++) {
        if (t[i] != 0) ok = false;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}