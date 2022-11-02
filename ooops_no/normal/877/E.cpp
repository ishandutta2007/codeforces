#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N], tin(N), tout(N);
int t[4 * N][2], add[4 * N];
int cnt = 0;

void upd(int v){
    t[v][0] = t[v * 2][0] + t[v * 2 + 1][0];
    t[v][1] = t[v * 2][1] + t[v * 2 + 1][1];
}

void push(int v){
    if (add[v]){
        swap(t[v][0], t[v][1]);
    }
    if (v * 2 < 4 * N){
        add[v * 2] ^= add[v];
        add[v * 2 + 1] ^= add[v];
    }
    add[v] = 0;
}

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v][val] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    upd(v);
}

void update2(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] ^= 1;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update2(v * 2, tl, tm, l, min(r, tm)), update2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    upd(v);
}

int get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return 0;
    if (tl == l && tr == r){
        return t[v][1];
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void dfs(int v){
    tin[v] = cnt++;
    for (auto to : g[v]){
        dfs(to);
    }
    tout[v] = cnt - 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++){
        int type;
        cin >> type;
        update(1, 0, n - 1, tin[i], type);
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int v;
        cin >> v;
        v--;
        if (s == "pow"){
            update2(1, 0, n - 1, tin[v], tout[v]);
        }
        else{
            cout << get(1, 0, n - 1, tin[v], tout[v]) << endl;
        }
    }
    return 0;
}