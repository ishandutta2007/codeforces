#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int t[2222], h[2222], m[2222];
int a[2222];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> h[i];
        cin >> m[i];
    }
    for (int i = 0; i < n; i++) a[i] = 0;
    int u = x;
    int v = 0;
    int c1 = 0;
    while (true) {
        int q = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]) continue;
            if (h[i] > u) continue;
            if (t[i] != v) continue;
            if (q == -1) q = i;
            else if (m[i] > m[q]) q = i;
        }
        if (q == -1) break;
        c1++;
        a[q] = 1;
        u += m[q];
        v = 1-v;
    }
    for (int i = 0; i < n; i++) a[i] = 0;
    u = x;
    v = 1;
    int c2 = 0;
    while (true) {
        int q = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]) continue;
            if (h[i] > u) continue;
            if (t[i] != v) continue;
            if (q == -1) q = i;
            else if (m[i] > m[q]) q = i;
        }
        if (q == -1) break;
        c2++;
        a[q] = 1;
        u += m[q];
        v = 1-v;
    }
    cout << max(c1,c2) << "\n";
}