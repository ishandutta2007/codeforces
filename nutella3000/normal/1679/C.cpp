#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = 1e6 + 3;


struct fenwick {
    vector<int> f;

    fenwick(int n) {
        f.resize(n+1);
    }
    void add(int x, int y) {
        for (; x < siz(f); x += (x&-x))
            f[x] += y;
    }
    int pref_get(int x) {
        int res = 0;
        for (; x; x -= x&-x)
            res += f[x];
        return res;
    }
    int get(int l, int r) {
        return pref_get(r) - pref_get(l-1);
    }
};

void run() {
    int n, q; cin >> n >> q;
    
    vector<int> xs(n+1), ys(n+1);
    fenwick f1(n), f2(n);
    for (int it = 1; it <= q; ++it) {
        int ty, x, y, x1, y1; cin >> ty >> x >> y;

        if (ty == 1) {
            if (!xs[x]) f1.add(x, 1);
            if (!ys[y]) f2.add(y, 1);
            ++xs[x];
            ++ys[y];
        } else if (ty == 2) {
            --xs[x];
            --ys[y];
            if (!xs[x]) f1.add(x, -1);
            if (!ys[y]) f2.add(y, -1);
        } else {
            cin >> x1 >> y1;
            int res = (f1.get(x, x1) == x1-x+1 || f2.get(y, y1) == y1-y+1);
            cout << (res ? "Yes" : "No") << endl;
        }
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}