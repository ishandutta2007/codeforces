#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;

ll n;
vector <pii > inp;
ll ans = 0;

map <pair <pii, pii >, int> mem;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    ans = n * (n - 1) * (n - 2) / 6;

    forn(i, n) {
        int x, y;
        cin >> x >> y;
        inp.puba(mapa(x, y));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (inp[i].ss == inp[j].ss) {
                mem[mapa(mapa(100500, inp[i].ss), mapa(100500, 100500))]++;
                continue;
            }
            int tmp = gcd(abs(inp[i].ff - inp[j].ff), abs(inp[i].ss - inp[j].ss));
            int dy = (inp[i].ss - inp[j].ss) / tmp;
            int dx = (inp[i].ff - inp[j].ff) / tmp;
            if (dy < 0) {
                dy *= -1;
                dx *= -1;
            }
            pii pos = inp[i];
            if (pos.ss < 0) {
                while (pos.ss < 0) {
                    pos.ss += dy;
                    pos.ff += dx;
                }
            } else {
                while (pos.ss - dy >= 0) {
                    pos.ss -= dy;
                    pos.ff -= dx;
                }
            }
            mem[mapa(pos, mapa(dy, dx))]++;
        }
    }

    for (map <pair <pii, pii >, int>::iterator it = mem.begin(); it != mem.end(); ++it) {
        int tmp = it -> ss;
        ll l = 0, r = n + 1;
        while (r - l > 1) {
            int med = (r + l) / 2;
            if (med * (med - 1) / 2 <= tmp) {
                l = med;
            } else {
                r = med;
            }
        }
        //cerr << it -> ff.ff << " " << it -> ff.ss << " " << l << endl;
        ans -= l * (l - 1) * (l - 2) / 6;
    }

    cout << ans << endl;

    return 0;
}