#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7, mod = 1e9 + 7;

int binpow(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}
int inv(int a) { return binpow(a, mod - 2); }


void run() {
    int n, m, x1, y1, x2, y2, p; 
    int dx = 1, dy = 1;
    int stx, sty;

    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> p;

    if (x1 == n) dx = -1;
    if (x1 == 1) dx = 1;
    if (y1 == m) dy = -1;
    if (y1 == 1) dy = 1;

    int sxx = dx, syy = dy;

    stx = x1, sty = y1;

    int c1 = 0, c2 = 0;


    int res = 1;
    int cuc = 0;

    do {


        if (x1 == x2 || y1 == y2) {
            ++c2;
            res = res * (1 - p * inv(100) % mod + mod) % mod;
        }
        cuc = (cuc + res) % mod;

        ++c1;

        x1 += dx, y1 += dy;

        if (x1 == n) dx = -1;
        if (x1 == 1) dx = 1;
        if (y1 == m) dy = -1;
        if (y1 == 1) dy = 1;

    } while(x1 != stx || y1 != sty || dx != sxx || dy != syy);
    
    cout << inv(1 - res + mod) * cuc % mod << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}