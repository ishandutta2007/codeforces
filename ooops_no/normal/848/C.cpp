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

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> save[4 * N], a, b;
vector<int> ans(N);
vector<set<int>> v(N);
int n, m;

struct st{
    vector<int> t;
    void clear(){
        t.clear();
    }
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

void relax(int i){
    if (v[a[i]].upper_bound(i) != v[a[i]].end()){
        upd(1, 0, n - 1, i, *v[a[i]].upper_bound(i));
    }
}

void relax2(int i, int f, bool rev){
    if (v[a[i]].upper_bound(i) != v[a[i]].end()){
        update(1, 0, n - 1, i, *v[a[i]].upper_bound(i), (rev ? (n - i) * f : f * (i + 1)));
    }
}

void solve(vector<vector<int>> qu, bool rev){
    if (rev){
        for (int i = 0; i < 4 * N; i++){
            save[i].clear();
            t[i].clear();
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = set<int>{n};
    }
    for (int i = 0; i < n; i++){
        v[a[i]].insert(i);
    }
    for (int i = 0; i < n; i++){
        relax(i);
    }
    for (int i = 0; i < m; i++){
        if (qu[i][0] == 1){
            int j = qu[i][1];
            v[a[j]].erase(j);
            auto it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax(*it);
            }
            a[j] = qu[i][2];
            v[a[j]].insert(j);
            relax(j);
            it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax(*it);
            }
        }
    }
    a = b;
    for (int i = 0; i < 4 * N; i++){
        sort(save[i].begin(), save[i].end());
        save[i].erase(unique(save[i].begin(), save[i].end()), save[i].end());
        t[i].make(save[i].size());
    }
    for (int i = 0; i < n; i++) {
        v[i] = set<int>{n};
    }
    for (int i = 0; i < n; i++){
        v[a[i]].insert(i);
    }
    for (int i = 0; i < n; i++){
        relax2(i, 1, rev);
    }
    for (int i = 0; i < m; i++){
        if (qu[i][0] == 2){
            if (!rev) ans[i] += get(1, 0, n - 1, qu[i][1], qu[i][2], qu[i][2] + 1);
            else {
                ans[i] -= get(1, 0, n - 1, qu[i][1], qu[i][2], qu[i][2] + 1);
            }
        }
        else{
            int j = qu[i][1];
            relax2(j, -1, rev);
            auto it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax2(*it, -1, rev);
            }
            v[a[j]].erase(j);
            it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax2(*it, 1, rev);
            }
            a[j] = qu[i][2];
            it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax2(*it, -1, rev);
            }
            v[a[j]].insert(j);
            relax2(j, 1, rev);
            it = v[a[j]].lower_bound(j);
            if (it != v[a[j]].begin()){
                it--;
                relax2(*it, 1, rev);
            }
        }
    }
    a = b;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    b = a;
    vector<vector<int>> qu(m, vector<int>(3));
    for (int i = 0; i < m; i++){
        cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
        qu[i][1]--, qu[i][2]--;
    }
    solve(qu, 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < m; i++){
        qu[i][1] = n - qu[i][1] - 1;
        if (qu[i][0] == 2){
            qu[i][2] = n - qu[i][2] - 1;
            swap(qu[i][1], qu[i][2]);
        }
    }
    solve(qu, 1);
    for (int i = 0; i < m; i++){
        if (qu[i][0] == 2) cout << ans[i] << endl;
    }
    return 0;
}