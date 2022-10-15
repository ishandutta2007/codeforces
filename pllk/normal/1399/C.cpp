#include <iostream>

using namespace std;

int n;
int w[55];
int c[55];

int check(int s) {
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[w[i]]++;
    int v = 0;
    for (int i = 1; i <= n; i++) {
        int u = s-w[i];
        if (u < 1 || u > n) continue;
        if (u == w[i]) {
            if (c[u] >= 2) {
                c[u] -= 2;
                v++;
            }
        } else {
            if (c[w[i]] && c[u]) {
                c[w[i]]--;
                c[u]--;
                v++;
            }
        }
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> w[i];
        int r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                r = max(r,check(w[i]+w[j]));
            }
        }
        cout << r << "\n";
    }
}