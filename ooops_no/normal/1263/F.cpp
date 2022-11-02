#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2010, INF = 1e18;
vector<int> g1[N], g2[N], sz1(N), sz2(N), tin1(N), tout1(N), tin2(N), tout2(N), par1(N), par2(N), d1(N), d2(N);
int cnt1 = 0, cnt2 = 0;

bool is_parent1(int a, int b) {
    return tin1[a] <= tin1[b] && tout1[b] <= tout1[a];
}

bool is_parent2(int a, int b) {
    return tin2[a] <= tin2[b] && tout2[b] <= tout2[a];
}

void dfs1(int v) {
    tin1[v] = cnt1++;
    d1[v] = 1;
    if (g1[v].size() == 0) {
        sz1[v] = 1;
    }
    for (auto to : g1[v]) {
        par1[to] = v;
        dfs1(to);
        d1[v] += d1[to];
        sz1[v] += sz1[to];
    }
    tout1[v] = cnt1++;
}

void dfs2(int v) {
    tin2[v] = cnt2++;
    d2[v] = 1;
    if (g2[v].size() == 0) {
        sz2[v] = 1;
    }
    for (auto to : g2[v]) {
        par2[to] = v;
        dfs2(to);
        d2[v] += d2[to];
        sz2[v] += sz2[to];
    }
    tout2[v] = cnt2++;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a;
    vector<int> x(n), y(n);
    for (int i = 1; i < a; i++) {
        int p;
        cin >> p;
        p--;
        g1[p].pb(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    cin >> b;
    for (int i = 1; i < b; i++) {
        int p;
        cin >> p;
        p--;
        g2[p].pb(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        y[i]--;
    }
    par1[0] = par2[0] = -1;
    dfs1(0);
    dfs2(0);
    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int res = 0, v = x[i];
        for (int j = i; j < n; j++) {
            if (v != 0 && is_parent1(par1[v], x[j])) {
                res++;
            }
            while (par1[v] != -1 && sz1[par1[v]] <= res) {
                v = par1[v];
            }
            dp[j + 1] = max(dp[j + 1], dp[i] + d1[v] - (v == 0));
        }
        res = 0, v = y[i];
        for (int j = i; j < n; j++) {
            if (v != 0 && is_parent2(par2[v], y[j])) {
                res++;
            }
            while (par2[v] != -1 && sz2[par2[v]] <= res) {
                v = par2[v];
            }
            dp[j + 1] = max(dp[j + 1], dp[i] + d2[v] - (v == 0));
        }
    }
    cout << dp.back() << endl;
    return 0;
}