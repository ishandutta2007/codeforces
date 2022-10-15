#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

#define N 1111111

int a[N+1];

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = u*u;
    u %= M;
    if (b%2 == 1) u *= a;
    u %= M;
    return u;
}

ll inv(int x) {
    return pot(x,M-2);
}

ll f[N+1];
ll g[N+1];

ll ncr(int a, int b) {
    if (b > a) return 0;
    ll u = f[a];
    u *= g[b];
    u %= M;
    u *= g[a-b];
    u %= M;
    return u;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= N; i++) {
        if (a[i]) continue;
        for (int j = 2*i; j <= N; j += i) {
            if (a[j] == 0) a[j] = i;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = f[i-1]*i;
        f[i] %= M;
    }
    g[0] = 1;
    g[N] = inv(f[N]);
    for (int i = N-1; i >= 1; i--) {
        g[i] = g[i+1];
        g[i] *= i+1;
        g[i] %= M;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int r, n;
        cin >> r >> n;
        ll z = 1;
        while (n != 1) {
            int u = a[n];
            if (u == 0) u = n;
            int c = 0;
            while (n%u == 0) {
                n /= u;
                c++;
            }
            if (c == 1 || r == 0) {
                z *= (r+2);
            } else {
                ll s = 0;
                for (int i = 0; i <= c; i++) {
                    ll h = ncr(r-1+i,r-1);
                    if (i < c) s += 2*h;
                    else s += h;
                    s %= M;
                }
                z *= s;
            }
            z %= M;
        }
        cout << z << "\n";
    }
}