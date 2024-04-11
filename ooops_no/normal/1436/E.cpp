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
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10;

int t[4 * N];

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    if (l > r) return 1e18;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), ans(n + 3);
    vector<vector<int>> need(n + 2, {-1});
    vector<vector<pair<int,int>>> ask(n + 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        need[a[i]].pb(i);
    }
    update(1, 0, N - 1, 0, 1e18);
    for (int i = 1; i <= n + 1; i++){
        need[i].pb(n);
        for (int j = 0; j + 1 < need[i].size(); j++){
            if (need[i][j] + 1 < need[i][j + 1]){
                ask[need[i][j + 1]].pb({need[i][j] + 2, i});
            }
        }
    }
    for (int i = 0; i <= n; i++){
        for (auto to : ask[i]){
            if (get(1, 0, N - 1, 0, to.second - 1) >= to.first){
                ans[to.second] = 1;
            }
        }
        if (i < n) update(1, 0, N - 1, a[i], i + 1);
    }
    int anss = 1;
    while(ans[anss]){
        anss++;
    }
    cout << anss << endl;
    return 0;
}