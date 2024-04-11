#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;
const int max_n = 1e6 + 1;
 
int a[max_n];
 
void add(int v, int x) {
    while(v < max_n) {
        a[v] += x;
        v = (v | (v + 1));
    }
}
 
int get(int r) {
    int res = 0;
    while(r >= 0) {
        res += a[r];
        r = (r & (r + 1)) - 1;
    }
    return res;
}
 
int get(int l, int r) {
    return get(r) - get(l - 1);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> ver(max_n);
    vector<vector<pii>> hor(max_n);
 
    int res = 0;

    for(int i = 0;i < n;i++) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        hor[x1].emplace_back(y, 1);
        hor[x2].emplace_back(y, -1);

        if (x1 == 0 && x2 == 1000000) res++;
    }
 
    for(int i = 0;i < m;i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;
        ver[x] = {y1, y2};

        if (y1 == 0 && y2 == 1000000) res++;
    }
 
 
    for(int i = 0;i < max_n;i++) {
        for(pii v : hor[i]) {
            if (v.se == 1)
                add(v.fi, v.se);
        }

        if (ver[i].se != 0) {
            res += get(ver[i].fi, ver[i].se);
        }

        for(pii v : hor[i]) {
            if (v.se == -1)
                add(v.fi, v.se);
        }
    }
 
    cout << res + 1;
}
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}