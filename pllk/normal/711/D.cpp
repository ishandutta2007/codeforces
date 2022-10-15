#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

int n;
int a[202020];
int c[202020];
int k;
int z[202020];
int g[202020];
ll p[202020];

int main() {
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = (p[i-1]*2)%M;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int x = i;
        if (c[x]) continue;
        while (true) {
            if (c[x]) break;
            c[x] = -1;
            x = a[x];
        }
        int u;
        int d = 0;
        if (c[x] == -1) {
            u = ++k;
            d = x;
        } else {
            u = c[x];
        }
        x = i;
        bool y = false;
        int t = 0;
        while (true) {
            if (y) t++;
            if (c[x] == u) break;
            c[x] = u;
            z[u]++;
            if (x == d) y = true;
            x = a[x];
        }
        if (d) g[k] = t;
    }
    ll f = 1;
    for (int i = 1; i <= k; i++) {
        ll u = p[g[i]]-2;
        if (u < 0) u += M;
        f *= u;
        f %= M;
        f *= p[z[i]-g[i]];
        f %= M;
    }
    cout << f << "\n";
}