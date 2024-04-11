#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

struct node {
    int pos, neg;
};

const int N = 1e5 + 10;
vector<node> t(4 * N);

node merge(node a, node b) {
    node c;
    if (a.pos == 1) {
        c.pos = b.pos;
    } else {
        c.pos = b.neg;
    }
    if (a.neg == 1) {
        c.neg = b.pos;
    } else {
        c.neg = b.neg;
    }
    return c;
}

void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
        if (val == 0) {
            t[v].pos = 1, t[v].neg = -1;
        } else if (val == 1){
            t[v].pos = 1, t[v].neg = 1;
        } else if (val == 2) {
            t[v].pos = -1, t[v].neg = -1;
        } else if (val == 3){
            t[v].pos = -1, t[v].neg = 1;
        }
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ans(n);
    map<int, vector<pair<int,int>>> need;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        need[abs(a[i])].pb({a[i], i});
    }
    vector<pair<char, int>> u(q);
    map<int, vector<pair<int,int>>> mp;
    for (int i = 0; i < q; i++) update(1, 0, q - 1, i, 0);
    for (int i = 0; i < q; i++) {
        cin >> u[i].first >> u[i].second;
        if (u[i].first == '<') {
            if (u[i].second <= 0) {
                mp[abs(u[i].second - 1)].pb({i, 1});
            } else {
                update(1, 0, q - 1, i, 3);
                mp[u[i].second].pb({i, 1});
            }
        } else {
            if (u[i].second < 0) {
                update(1, 0, q - 1, i, 3);
                mp[abs(u[i].second)].pb({i, 2});
            } else {
                mp[u[i].second + 1].pb({i, 2});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (auto to : mp[i]) {
            update(1, 0, q - 1, to.first, to.second);
        }
        for (auto to : need[i]) {
            if (to.first > 0) {
                ans[to.second] = abs(to.first) * t[1].pos;
            } else {
                ans[to.second] = abs(to.first) * t[1].neg;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}