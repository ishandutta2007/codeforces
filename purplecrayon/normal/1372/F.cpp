#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

vector<int> hidden{1, 2, 3, 4, 5, 7, 8};

int cnt_queries = 0;
struct Q {
    int l, r;
    int x, cnt;

    Q(int _l, int _r): l(_l), r(_r) {}
    Q(int _l, int _r, int _x, int _cnt): l(_l), r(_r), x(_x), cnt(_cnt) {}

    void read() {
        /*
        cnt_queries++;
        map<int, int> mp;
        for (int i = l; i <= r; i++) mp[hidden[i]]++;
        pair<int, int> best{-1, -1};
        for (auto [v, k] : mp) {
            best = max(best, {k, -v});
        }
        x = -best.second;
        cnt = best.first;
        */
        cout << "? " << l+1 << ' ' << r+1 << endl;
        cin >> x >> cnt;
    }
};

Q empty() {
    return Q(-1, -1, -1, -1);
}

int n;
vector<int> ans;

set<int> s;
void rec(int l, int r, Q par) {
    while (l <= r && ans[l] != -1) l++;
    while (l <= r && ans[r] != -1) r--;
    if (l > r) return;

    Q cur(l, r); cur.read();
    if (s.count(cur.x)) {
        for (int i = l; i < l + cur.cnt; i++) ans[i] = cur.x;
        rec(l + cur.cnt, r, empty());
        return;
    }
    if (par.x == cur.x && cur.cnt != par.cnt) {
        int me = cur.cnt, he = par.cnt - cur.cnt;
        bool left_child = (par.l == l);
        if (left_child) {
            for (int i = r; i > r - me; i--) ans[i] = cur.x;
            for (int i = r + 1; i <= r + he; i++) ans[i] = cur.x;
            rec(l, r - me, empty());
            return;
        } else {
            for (int i = l; i < l + me; i++) ans[i] = cur.x;
            for (int i = l - he; i < l; i++) ans[i] = cur.x;
            rec(l + me, r, empty());
            return;
        }
    }
    if (cur.cnt == r - l + 1) {
        for (int i = l; i <= r; i++) ans[i] = cur.x;
        s.insert(cur.x);
        return;
    }
    int m = (l + r) / 2;
    rec(l, m, cur), rec(m + 1, r, cur);
}
void solve() {
    cin >> n;
    // n = sz(hidden);
    ans.assign(n, -1);
    rec(0, n-1, empty());
    cout << "! ";
    for (int x : ans) cout << x << ' ';
    cout << endl;

    /*
    cerr << "queries: " << cnt_queries << endl;
    int cnt_distinct = 1;
    for (int i = 1; i < n; i++) cnt_distinct += hidden[i] != hidden[i-1];
    cerr << "limit: " << cnt_distinct * 4 << endl;
    int extra = cnt_distinct * 4 - cnt_queries;
    cerr << "extra: " << extra << endl;
    */
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}