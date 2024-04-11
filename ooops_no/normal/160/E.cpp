#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include<deque>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#define pb emplace_back
#define ld long double
//#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10, INF = 2e9;
vector<int> save[4 * N];

struct st{
    vector<int> t;
    void make(int n){
        t.resize(n);
        fill(t.begin(), t.end(), INF);
    }
    void inc(int i, int d){
        for (; i < t.size(); i = (i | (i + 1))){
            t[i] = min(t[i], d);
        }
    }
    int get(int r){
        int ans = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ans = min(ans, t[r]);
        }
        return ans;
    }
} t[4 * N];

void upd(int v, int l, int r, int pos, int val){
    save[v].pb(val);
    if (l == r){
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(2 * v, l, m, pos, val);
    else upd(2 * v + 1, m + 1, r, pos, val);
}

void update(int v, int l, int r, int pos, int val, int tt){
    int j = save[v].size() - 1 - (lower_bound(save[v].begin(), save[v].end(), val) - save[v].begin());
    t[v].inc(j, tt);
    //cout << j << ' ' << save[v].size() << endl;
    if (l == r){
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val, tt);
    else update(2 * v + 1, m + 1, r, pos, val, tt);
}

int get(int v, int tl, int tr, int l, int r, int val){
    if (l > r) return INF;
    if (tl == l && tr == r){
        int j = lower_bound(save[v].begin(), save[v].end(), val) - save[v].begin();
        if (j == save[v].size()){
            return INF;
        }
        return t[v].get(save[v].size() - j - 1);
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(r, tm), val), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val));
}

struct event{
    int i, t, l, r;
};

bool cmp(event a, event b){
    return a.t > b.t || (a.t == b.t && a.i > b.i);
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
    vector<int> s(n), f(n), time(n), l(m), r(m), b(m), u{INF};
    map<int,int> take;
    vector<event> a;
    for (int i = 0; i < n; i++){
        cin >> s[i] >> f[i] >> time[i];
        //u.pb(s[i]);
        u.pb(f[i]);
        take[time[i]] = i + 1;
    }
    take[INF] = -1;
    for (int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> b[i];
        u.pb(l[i]);
        u.pb(r[i]);
    }
    u.pb(INF);
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 0; i < n; i++){
        s[i] = lower_bound(u.begin(), u.end(), s[i]) - u.begin();
        f[i] = lower_bound(u.begin(), u.end(), f[i]) - u.begin();
        upd(1, 0, N - 1, s[i], f[i]);
        a.pb(event{i + 1, time[i], s[i], f[i]});
    }
    for (int i = 0; i < m; i++){
        l[i] = lower_bound(u.begin(), u.end(), l[i]) - u.begin();
        r[i] = lower_bound(u.begin(), u.end(), r[i]) - u.begin();
        a.pb(event{-(i + 1), b[i], l[i], r[i]});
    }
    for (int i = 0; i < 4 * N; i++){
        t[i].make(save[i].size());
        sort(save[i].begin(), save[i].end());
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> ans(m);
    for (auto to : a){
        //cout << to.i << ' ' << to.t << ' ' << to.l << ' ' << to.r << endl;
        if (to.i > 0){
            update(1, 0, N - 1, to.l, to.r, to.t);
        }
        else{
            //cout << to.i << endl;
            int val = get(1, 0, N - 1, 0, to.l, to.r);
            ans[abs(to.i) - 1] = val;
        }
    }
    for (auto to : ans){
        cout << take[to] << ' ';
    }
    cout << endl;
    return 0;
}