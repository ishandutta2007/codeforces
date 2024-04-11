#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int a[303030];
#define F 1000000
int f[F+1];

int r[303030];

int re(int x) {
    int v = 1;
    while (f[x]) {
        int u = f[x];
        int c = 0;
        while (f[x] == u) {
            x /= u;
            c++;
        }
        if (x == u) {
            x /= u;
            c++;
        }
        if (c%2 == 1) v *= u;
    }
    v *= x;
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= F; i++) {
        if (f[i]) continue;
        for (int j = 2*i; j <= F; j += i) {
            if (f[j] == 0) f[j] = i;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int,int> ma;
        r[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            auto v = re(a[i]);
            ma[v]++;
            r[0] = max(r[0],ma[v]);
        }
        r[1] = r[0];
        for (auto z : ma) {
            if (z.first != 1 && ma[z.first]%2 == 0) {
                ma[1] += ma[z.first];
                r[1] = max(r[1],ma[1]);
            }
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            ll w;
            cin >> w;
            if (w >= 1) w = 1;
            cout << r[w] << "\n";
        }
    }
}