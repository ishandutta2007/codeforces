#include <bits/stdc++.h>


using namespace std;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ld long double
#define int long long

const int max_n = (1 << 20);

pair<int, int> t[2 * max_n], max_push[2 * max_n];

void init() {
    fill(t, t + 2 * max_n, make_pair(-1, -1));
    fill(max_push, max_push + 2 * max_n, make_pair(-1, -1));
}

void push(int v) {
    t[v] = max(t[v], max_push[v]);
    if (max_push[v].first != -1) {
        max_push[v * 2] = max(max_push[v * 2], max_push[v]);
        max_push[v * 2 + 1] = max(max_push[v * 2 + 1], max_push[v]);
        max_push[v] = {-1, -1};
    }
}

pair<int, int> get_point(int v) {
    return max(t[v], max_push[v]);
}

void upd_point(int v) {
    t[v] = max(get_point(v * 2), get_point(v * 2 + 1));
}

void upd(int v, int tl, int tr, int l, int r, pair<int, int> x) {
    if (tl > r || l > tr)return;
    if (l <= tl && tr <= r)max_push[v] = max(max_push[v], x);
    else {
        int tm = (tl + tr) / 2;
        push(v);
        upd(v * 2, tl, tm, l, r, x);
        upd(v * 2 + 1, tm + 1, tr, l, r, x);
        upd_point(v);
    }
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r)return {-1, -1};
    if (l <= tl && tr <= r)return get_point(v);
    int tm = (tl + tr) / 2;
    push(v);
    auto res = max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
    upd_point(v);
    return res;
}

pair<int, int> get(int l, int r) {
    return get(1, 0, max_n - 1, l, r);
}

void upd(int l, int r, pair<int, int> x) {
    upd(1, 0, max_n - 1, l, r, x);
}

int n, m;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n >> m;
    vector<vector<pair<int, int>>> segments(n);
    map<int, int> tt;
    vector<int> vals;
    for (int i = 0; i < m; ++i) {
        int id, l, r;
        cin >> id >> l >> r;
        vals.push_back(l);
        vals.push_back(r);
        segments[id - 1].push_back({l, r});
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < segments[i].size(); ++j) {
            segments[i][j].first = lower_bound(all(vals), segments[i][j].first) - vals.begin();
            segments[i][j].second = lower_bound(all(vals), segments[i][j].second) - vals.begin();
        }
    }

    vector<int> dp(n), par(n);
    for (int i = 0; i < n; ++i) {
        pair<int, int> q = {-1, -1};
        for (auto z : segments[i]) {
            int l = z.first, r = z.second;
            q = max(q, get(l, r));
        }
        q.first = max(q.first, 0ll);
        dp[i] = q.first + 1;
        par[i] = q.second;
        for (auto z : segments[i]) {
            int l = z.first, r = z.second;
            upd(l, r, {dp[i], i});
        }
    }

    int res = 0, id_res = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > res) {
            res = dp[i];
            id_res = i;
        }
    }
    vector<bool> rem(n, true);
    int i = id_res;
    while(i != -1){
        rem[i] = false;
        i = par[i];
    }

    vector<int> ress;
    for(int j = 0; j < n; ++j){
         if(rem[j])ress.push_back(j);
    }

    cout << ress.size() << '\n';
    for(int x : ress)cout << x + 1 << " ";
}