#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int mod = 998244353;
const int max_n = 2e5 + 1;

int d[max_n];
pip req[max_n];

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int rev(int k) {
    return binpow(k, mod - 2);
}

void solve() {
    int n, m;

    cin >> n >> m;

    int p = 0, s = 0, id = 0;

    for(int i = 0;i < n;i++) {
        cin >> d[i];
        s += d[i];
    }

    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        req[i] = mp(i, mp(a, b));
    }

    sort(d, d + n);
    sort(req, req + m, [](pip v1, pip v2) {return v1.se.se < v2.se.se;});

    vector<int> res(m);

    for(int temp = 0;temp < m;temp++) {
        pip r = req[temp];
        while(id < n && d[id] < r.se.se) {
            s -= d[id];
            p += d[id];
            id++;
        }
        int k = n - id;
        if (k == 0) continue;
        if (r.se.fi > k) continue;

        res[r.fi] = (s % mod * (k - r.se.fi) % mod * rev(k) + p % mod * (k + 1 - r.se.fi) % mod * rev(k + 1)) % mod + mod;
        //cout << k << " " << r.se.fi << " " << res[r.fi] << endl;
    }

    for(int i : res)
        cout << i % mod << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}