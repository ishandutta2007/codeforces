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
//#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> save[4 * N];

struct st{
    vector<int> t;
    void make(int n){
        t.resize(n);
    }
    void inc(int i, int d){
        for (; i < t.size(); i = (i | (i + 1))){
            t[i] += d;
        }
    }
    int get(int r){
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
} t[4 * N];

void upd(int v, int l, int r, int pos, int val){
    save[v].pb(val);
    if (l == r) return;
    int m = (l + r) / 2;
    if (pos <= m) upd(2 * v, l, m, pos, val);
    else upd(2 * v + 1, m + 1, r, pos, val);
}

void update(int v, int l, int r, int pos, int val, int need){
    int j = lower_bound(save[v].begin(), save[v].end(), val) - save[v].begin();
    t[v].inc(j, need);
    if (l == r) return;
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val, need);
    else update(2 * v + 1, m + 1, r, pos, val, need);
}

int get(int v, int tl, int tr, int l, int r, int val){
    if (l > r) return 0;
    if (tl == l && tr == r){
        int j = lower_bound(save[v].begin(), save[v].end(), val) - save[v].begin();
        if (j == save[v].size()){
            return 0;
        }
        return t[v].get(j, save[v].size() - 1);
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm), val) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
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
    vector<int> a(n), b(n), ind(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        ind[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        upd(1, 0, N - 1, i, ind[b[i]]);
    }
    vector<int> rem = b;
    vector<vector<int>> q;
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (t == 1){
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            la--, ra--, lb--, rb--;
            q.pb({la, ra, lb, rb});
        }
        else{
            int x, y;
            cin >> x >> y;
            x--, y--;
            swap(b[x], b[y]);
            upd(1, 0, N - 1, x, ind[b[x]]);
            upd(1, 0, N - 1, y, ind[b[y]]);
            q.pb({x, y});
        }
    }
    b = rem;
    for (int i = 0; i < 4 * N; i++){
        sort(save[i].begin(), save[i].end());
        save[i].erase(unique(save[i].begin(), save[i].end()), save[i].end());
        t[i].make(save[i].size());
    }
    for (int i = 0; i < n; i++){
        update(1, 0, N - 1, i, ind[b[i]], 1);
    }
    for (auto to : q){
        if (to.size() == 4){
            int la = to[0], ra = to[1], lb = to[2], rb = to[3];
            cout << get(1, 0, N - 1, lb, rb, la) - get(1, 0, N - 1, lb, rb, ra + 1) << endl;
        }
        else{
            int x = to[0], y = to[1];
            update(1, 0, N - 1, x, ind[b[x]], -1);
            update(1, 0, N - 1, y, ind[b[y]], -1);
            swap(b[x], b[y]);
            update(1, 0, N - 1, x, ind[b[x]], 1);
            update(1, 0, N - 1, y, ind[b[y]], 1);
        }
    }
    return 0;
}