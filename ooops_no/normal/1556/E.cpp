#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
int t_min[4 * N], t_max[4 * N];

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t_min[v] = t_max[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t_min[v] = min(t_min[v * 2], t_min[v * 2 + 1]);
    t_max[v] = max(t_max[v * 2], t_max[v * 2 + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r){
    if (l > r){
        return {1e18, -1e18};
    }
    if (tl == l && tr == r){
        return {t_min[v], t_max[v]};
    }
    int tm = (tl + tr) / 2;
    pair<int,int> p = get(2 * v, tl, tm, l, min(r, tm)), pp = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return {min(p.first, pp.first), max(p.second, pp.second)};
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    vector<int> pr(n), prr(n), pref(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pr[i] = a[i] + (i > 0 ? pr[i - 1] : 0);
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        prr[i] = b[i] + (i > 0 ? prr[i - 1] : 0);
    }
    for (int i = 0; i < n; i++){
        pref[i] = b[i] - a[i] + (i > 0 ? pref[i - 1] : 0);
        update(1, 0, n - 1, i, pref[i]);
    }
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int sum_a = pr[r] - (l > 0 ? pr[l - 1] : 0), sum_b = prr[r] - (l > 0 ? prr[l - 1] : 0);
        if (sum_a != sum_b){
            cout << -1 << endl;
        }
        else{
            pair<int,int> p = get(1, 0, n - 1, l, r);
            if (p.first - (l > 0 ? pref[l - 1] : 0) < 0){
                cout << -1 << endl;
                continue;
            }
            cout << p.second - (l > 0 ? pref[l - 1] : 0) << endl;
        }
    }
    return 0;
}