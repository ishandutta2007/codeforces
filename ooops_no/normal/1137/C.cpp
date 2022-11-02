#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 1e5 * 50 + 10;
vector<int> g[N], gr[N], gg[N];
int sum[N];
vector<int> comp(N, -1);
vector<char> usedd(N);
vector<char> used(N);
int cnt = 1, n, m, d;
set<int> st;
vector<int> ans;

void dfs(int v){
    usedd[v] = 1;
    int a = v % n;
    for (auto to : g[a]){
        int b = (v - a + to + n);
        if (b >= n * d) b -= n * d;
        if (!usedd[b]){
            dfs(b);
        }
    }
    ans.pb(v);
}

void dfs2(int v){
    comp[v] = cnt;
    int u = v % n;
    if (used[v]){
        st.insert(u);
    }
    for (auto to : gr[u]){
        int b = (v - u + to - n);
        if (b < 0) b += n * d;
        if (comp[b] == -1) dfs2(b);
    }
}

void zhfs(int v){
    usedd[v] = 1;
    for (auto to : gg[v]){
        if (!usedd[to]){
            zhfs(to);
        }
    }
    ans.pb(v);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        gr[b].pb(a);
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < d; j++){
            used[i + n * j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n * d; i++){
        if (!usedd[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
    int need = -1;
    for (auto i : ans){
        if (comp[i] == -1){
            if (i == 0) need = cnt;
            dfs2(i);
            sum[cnt] = st.size();
            cnt++;
            st.clear();
        }
    }
    for (int i = 0; i < N; i++){
        gr[i].clear();
        gr[i].shrink_to_fit();
    }
    for (int i = 0; i < n * d; i++){
        int a = i % n;
        for (auto to : g[a]){
            int b = (i - a + to + n);
            if (b >= n * d) b -= n * d;
            if (comp[i] != comp[b]){
                gg[comp[i]].pb(comp[b]);
            }
        }
    }
    used.clear();
    used.shrink_to_fit();
    for (int i = 0; i < N; i++){
        g[i].clear();
        g[i].shrink_to_fit();
    }
    fill(usedd.begin(), usedd.end(), 0);
    ans.clear();
    ans.shrink_to_fit();
    comp.clear();
    comp.shrink_to_fit();
    for (int i = 1; i < cnt; i++){
        if (!usedd[i]){
            zhfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    int anss = 0;
    vector<int> dp(N, -1e9);
    for (auto to : ans){
        if (to == need) dp[to] = 0;
        dp[to] += sum[to];
        for (auto t : gg[to]){
            dp[t] = max(dp[t], dp[to]);
        }
        anss = max(anss, dp[to]);
    }
    cout << anss << endl;
    return 0;
}