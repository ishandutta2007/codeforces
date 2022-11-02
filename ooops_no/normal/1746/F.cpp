#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Fenwick {
    vector<int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] += d;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

const int T = 40, N = 6e5 + 10;
vector<vector<bool>> need(T, vector<bool>(N));

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int,int> ind;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!ind.count(a[i])) {
            ind[a[i]] = ind.size();
        }
        a[i] = ind[a[i]];
    }
    vector<vector<int>> qu;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, x;
            cin >> pos >> x;
            pos--;
            if (!ind.count(x)) {
                ind[x] = ind.size();
            }
            qu.pb({type, pos, ind[x]});
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            qu.pb({type, l, r, k});
        }
    }
    int sz = ind.size();
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < sz; j++) {
            if (rnd() % 2) {
                need[i][j] = 1;
            }
        }
    }
    vector<Fenwick> t(T, Fenwick(n));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n; j++) {
            if (need[i][a[j]]) {
                t[i].inc(j, 1);
            }
        }
    }
    for (int i = 0; i < qu.size(); i++) {
        if (qu[i][0] == 1) {
            int pos = qu[i][1], x = qu[i][2];
            for (int j = 0; j < T; j++) {
                if (need[j][a[pos]]) {
                    t[j].inc(pos, -1);
                }
                if (need[j][x]) {
                    t[j].inc(pos, 1);
                }
            }
            a[pos] = x;
        } else {
            int l = qu[i][1], r = qu[i][2], k = qu[i][3];
            bool good = 1;
            for (int j = 0; j < T; j++) {
                good &= t[j].get(l, r) % k == 0;
            }
            cout << (good ? "YES\n" : "NO\n");
        }
    }
    return 0;
}