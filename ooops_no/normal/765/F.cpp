#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10, INF = 1e9;
vector<int> ans(N, INF);
vector<int> t(4 * N, -INF);
int n, m;

struct st{
    vector<int> t;
    void build(int n){
        t.resize(4 * n, INF);
    }
    void pull(int v){
        if (v * 2 < t.size()){
            t[v * 2] = min(t[v * 2], t[v]);
            t[v * 2 + 1] = min(t[v * 2 + 1], t[v]);
        }
    }
    void update(int v, int tl, int tr, int l, int r, int val){
        pull(v);
        if (l > r) return;
        if (tl == l && tr == r){
            t[v] = min(t[v], val);
            pull(v);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    int get(int v, int l, int r, int pos){
        pull(v);
        if (l == r){
            return t[v];
        }
        int m = (l + r) / 2;
        if (pos <= m) return get(2 * v, l, m, pos);
        else return get(2 * v + 1, m + 1, r, pos);
    }
};

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    if (l > r) return -INF;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve(vector<int> a, vector<pair<int,int>> q){
    for (int i = 0; i < 4 * N; i++) t[i] = -INF;
    vector<vector<pair<int,int>>> need(n);
    vector<pair<int,int>> u;
    for (int i = 0; i < m; i++){
        need[q[i].second].pb({q[i].first, i});
    }
    for (int i = 0; i < n; i++){
        u.pb({a[i], i});
    }
    sort(u.begin(), u.end());
    st T;
    T.build(n);
    map<int,int> last;
    for (int i = 0; i < n; i++){
        int j = lower_bound(u.begin(), u.end(), make_pair(a[i], i)) - u.begin(), val = INF;
        if (last[a[i]] != 0){
            T.update(1, 0, n - 1, 0, last[a[i]] - 1, 0);
            last[a[i]] = i + 1;
        }
        last[a[i]] = i + 1;
        while(val > 0){
            int k = lower_bound(u.begin(), u.end(), make_pair(val + a[i] + 1, 0)) - u.begin() - 1;
            int res = get(1, 0, n - 1, j, k);
            if (res == -INF) break;
            T.update(1, 0, n - 1, 0, res, a[res] - a[i]);
            val = (a[res] - a[i]) / 2;
        }
        for (auto to : need[i]){
            ans[to.second] = min(ans[to.second], T.get(1, 0, n - 1, to.first));
        }
        update(1, 0, n - 1, j, i);
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    vector<pair<int,int>> u(m);
    for (int i = 0; i < m; i++){
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
    }
    solve(a, u);
    for (int i = 0; i < n; i++){
        a[i] = -a[i];
    }
    solve(a, u);
    for (int i = 0; i < m; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}