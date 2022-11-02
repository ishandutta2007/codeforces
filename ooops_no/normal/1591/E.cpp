#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 1e6 + 10;
int a[N], cnt[N], ans[N], t[N];
vector<int> g[N];
vector<vector<int>> need[N];
vector<int> all[N];
int n, q;

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

int get_ans(int L, int k){
    int now = get(N - 1), val = get(L - 1);
    if (now - val < k){
        return -1;
    }
    else{
        int l = L - 1, r = N;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (get(mid) - val >= k){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return r;
    }
}

void clean(int i){
    while(all[i].size() > 0 && cnt[all[i].back()] != i){
        all[i].pop_back();
    }
}

void make(int v, int add){
    inc(cnt[a[v]], -1);
    cnt[a[v]] += add;
    all[cnt[a[v]]].pb(a[v]);
    inc(cnt[a[v]], 1);
}

void dfs(int v, int p){
    make(v, 1);
    for (auto to : need[v]){
        int l = to[0], k = to[1], i = to[2];
        int val = get_ans(l, k);
        if (val == -1){
            ans[i] = val;
        }
        else{
            clean(val);
            ans[i] = all[val].back();
        }
    }
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
        }
    }
    make(v, -1);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> q;
        for (int i = 0; i < n; i++){
            g[i].clear();
            need[i].clear();
        }
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 1; i < n; i++){
            int p;
            cin >> p;
            p--;
            g[i].pb(p);
            g[p].pb(i);
        }
        for (int i = 0; i < q; i++){
            int v, l, k;
            cin >> v >> l >> k;
            v--;
            need[v].pb({l, k, i});
        }
        dfs(0, -1);
        for (int i = 0; i < q; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}