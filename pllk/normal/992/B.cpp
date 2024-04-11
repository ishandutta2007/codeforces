#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll l, r, x, y;
ll t;

vector<int> f;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

void fac(int x) {
    for (int u = 2; u*u <= x; u++) {
        while (x%u == 0) {
            f.push_back(u);
            x /= u;
        }
    }
    if (x != 1) f.push_back(x);
}

ll cc;

void lol(int k, ll z, int g) {
    ll a = z;
    ll b = t/z;
    if (g == 1 && a >= l && b >= l && a <= r && b <= r && gcd(a,b) == x) cc++;
    if (z > r || k == f.size()) return;
    lol(k+1,z,0);
    if (g == 1 || f[k-1] != f[k]) lol(k+1,z*f[k],1);
}

int main() {
    cin >> l >> r >> x >> y;
    fac(x);
    fac(y);
    sort(f.begin(),f.end());
    t = x*y;
    lol(0,1,1);
    cout << cc << "\n";
}