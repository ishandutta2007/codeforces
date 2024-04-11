#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 6e5 + 10;
pair<int,int> t[4 * N], add[4 * N];

void push(int v){
    t[v] = max(t[v], add[v]);
    if (v * 2 < 4 * N){
        add[v * 2] = max(add[v * 2], add[v]);
        add[v * 2 + 1] = max(add[v * 2 + 1], add[v]);
    }
    add[v] = make_pair(0ll, 0ll);
}

void update(int v, int tl, int tr, int l, int r, pair<int,int> upd){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] = max(add[v], upd);
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), upd), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, upd);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return make_pair(0ll, 0ll);
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> a(n);
    vector<int> u;
    for (int i = 0; i < m; i++){
        int j, l, r;
        cin >> j >> l >> r;
        j--, l--, r--;
        u.pb(l);
        u.pb(r);
        a[j].pb({l, r});
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i].size(); j++){
            a[i][j].first = lower_bound(u.begin(),  u.end(), a[i][j].first) - u.begin();
            a[i][j].second = lower_bound(u.begin(), u.end(), a[i][j].second) - u.begin();
        }
    }
    vector<int> dp(n), par(n);
    for (int i = 0; i < n; i++){
        pair<int,int> p{0ll, 0ll};
        for (auto to : a[i]){
            p = max(p, get(1, 0, N - 1, to.first, to.second));
        }
        par[i] = (p.first == 0 ? -1 : p.second);
        dp[i] = p.first + 1;
        for (auto to : a[i]){
            update(1, 0, N - 1, to.first, to.second, {dp[i], i});
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++){
        if (dp[i] > dp[j]){
            j = i;
        }
    }
    vector<bool> used(n);
    int ans = n;
    while(j != -1){
        used[j] = 1;
        ans--;
        j = par[j];
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
    return 0;
}