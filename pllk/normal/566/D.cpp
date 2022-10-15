#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int g[202020];
int s[202020];
int n, q;
int h[202020];

bool sama(int a, int b) {
    while (g[a] != a) a = g[a];
    while (g[b] != b) b = g[b];
    return a == b;
}

void liita(int a, int b) {
    while (g[a] != a) a = g[a];
    while (g[b] != b) b = g[b];
    if (a == b) return;
    if (s[a] > s[b]) {
        s[a] += s[b];
        g[b] = g[a];
    } else {
        s[b] += s[a];
        g[a] = g[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        g[i] = i;
        s[i] = 1;
        h[i] = i+1;
    }
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            liita(x,y);
        }
        if (t == 2) {
            for (int j = x+1; j <= y;) {
                liita(x,j);
                int u = h[j];
                h[j] = max(h[j],y+1);
                j = u;
            }
            h[x] = y+1;
        }
        if (t == 3) {
            if (sama(x,y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}