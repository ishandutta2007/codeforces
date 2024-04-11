#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10, K = sqrt(1e6);
vector<int> g[N], in(N), out(N), d(N), rev(N);
int po[20][N], t[2 * N];
int cnt = 0;
int L = 0, R = 0;
int n, q;

void inc(int i, int val){
    i += N;
    t[i] += val;
    for (; i > 1; i /= 2) t[i / 2] = t[i] + t[i ^ 1];
}

int get(int l, int r){
    l += N, r += N + 1;
    int ans = 0;
    while(l < r){
        if (l & 1){
            ans += t[l];
            l++;
        }
        if (r & 1){
            r--;
            ans += t[r];
        }
        l /= 2, r /= 2;
    }
    return ans;
}

bool cmp(pair<pair<int,int>, int> aa, pair<pair<int,int>, int> bb){
    auto a = aa.first, b = bb.first;
    return a.first / K < b.first / K || (a.first / K == b.first / K && ((a.first / K) & 1 ? a.second < b.second : a.second > b.second));
}

void dfs(int v, int p){
    rev[cnt] = v;
    in[v] = cnt++;
    for (auto to : g[v]){
        if (to != p){
            po[0][to] = v;
            d[to] = d[v] + 1;
            dfs(to, v);
        }
    }
    out[v] = cnt - 1;
}

void movee(int l, int r){
    while(l < L){
        L--;
        inc(in[L], 1);
    }
    while(L < l){
        inc(in[L], -1);
        L++;
    }
    while(r < R){
        inc(in[R], -1);
        R--;
    }
    while(R < r){
        R++;
        inc(in[R], 1);
    }
}

int check(int l, int r){
    if (get(l, r) == 0){
        return -1;
    }
    int st = l;
    l--;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (get(st, mid) == 1){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return rev[r];
}

pair<int,int> ans(int v, int need){
    int st = v;
    for (int i = 19; i >= 0; i--){
        int u = po[i][v];
        if (get(in[u], out[u]) < need){
            v = po[i][v];
        }
    }
    if (get(in[v], out[v]) < need){
        v = po[0][v];
    }
    if (get(in[v], out[v]) > need){
        return {st, d[v]};
    }
    int f = check(0, in[v] - 1), s = check(out[v] + 1, n - 1);
    if (f != -1){
        return {f, d[v]};
    }
    else{
        return {s, d[v]};
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++){
        int p;
        cin >> p;
        g[i].pb(p);
        g[p].pb(i);
    }
    dfs(1, -1);
    po[0][1] = 1;
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    vector<pair<pair<int,int>, int>> a(q);
    vector<pair<int,int>> anss(q);
    for (int i = 0; i < q; i++){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), cmp);
    L = a[0].first.first, R = a[0].first.second;
    for (int i = L; i <= R; i++){
        inc(in[i], 1);
    }
    for (int i = 0; i < a.size(); i++){
        movee(a[i].first.first, a[i].first.second);
        pair<int, int> p = ans(a[i].first.first,  a[i].first.second - a[i].first.first), pp = ans(a[i].first.second, a[i].first.second - a[i].first.first);
        if (p.second > pp.second){
            anss[a[i].second] = p;
        }
        else{
            anss[a[i].second] = pp;
        }
    }
    for (auto to : anss){
        cout << to.first << ' ' << to.second << endl;
    }
    return 0;
}