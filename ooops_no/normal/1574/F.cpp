#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10, MOD = 998244353;
vector<bool> used(N);
set<int> g[N], gr[N];
vector<int> col(N);
set<int> st;

void dfs(int v, int cnt){
    if (used[v]) return;
    if (g[v].size() == 0){
        st.insert(cnt);
        col[cnt]++;
        return;
    }
    dfs(*g[v].begin(), cnt + 1);
}

int mul(int a, int b){
    return (a * b % MOD);
}

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void dfs2(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
    for (auto to : gr[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        v[i].resize(c);
        map<int,int> cnt;
        for (int j = 0; j < c; j++){
            cin >> v[i][j];
            v[i][j]--;
            cnt[v[i][j]]++;
        }
        bool x = 1;
        for (auto to : cnt){
            x &= (to.second == 1);
        }
        if (!x){
            for (auto to : cnt){
                used[to.first] = 1;
            }
        }
        else{
            for (int j = 0; j < c - 1; j++){
                g[v[i][j]].insert(v[i][j + 1]);
                gr[v[i][j + 1]].insert(v[i][j]);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (g[i].size() >= 2 || gr[i].size() >= 2){
            used[i] = 1;
        }
    }
    for (int i = 0; i < k; i++){
        if (used[i]){
            dfs2(i);
        }
    }
    for (int i = 0; i < k; i++){
        if (gr[i].size() == 0) dfs(i, 1);
    }
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++){
        for (auto to : st){
            if (i - to >= 0){
                dp[i] = add(dp[i], mul(dp[i - to], col[to]));
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}