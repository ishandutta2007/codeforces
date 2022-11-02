#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

const int N = 2e5 + 10;
const int MOD = 998244353;
vector<int> g[2][N];
int d[N][20];

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[0][a].pb(b);
        g[1][b].pb(a);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 20; j++){
            d[i][j] = 1e18;
        }
    }
    d[1][0] = 0;
    set<pair<int, pair<int,int>>> st;
    st.insert({0, {1, 0}});
    while(!st.empty()){
        int v = st.begin()->second.first, k = st.begin()->second.second;
        st.erase(st.begin());
        if (k + 1 < 20 && d[v][k + 1] > d[v][k] + (1 << k)){
            st.erase({d[v][k + 1], {v, k + 1}});
            d[v][k + 1] = d[v][k] + (1 << k);
            st.insert({d[v][k + 1], {v, k + 1}});
        }
        for (auto to : g[k % 2][v]){
            if (d[to][k] > d[v][k] + 1){
                st.erase({d[to][k], {to, k}});
                d[to][k] = d[v][k] + 1;
                st.insert({d[to][k], {to, k}});
            }
        }
    }
    int ans = d[n][0];
    for (int i = 0; i < 20; i++){
        ans = min(ans, d[n][i]);
    }
    if (ans == 1e18){
        pair<int,int> u[n + 1][2];
        for (int i = 0; i <= n; i++){
            for (int j = 0; j < 2; j++){
                u[i][j] = {1e18, 1e18};
            }
        }
        u[1][0] = {0, 0};
        deque<pair<int,int>>q;
        q.pb({1, 0});
        int kek = 1e18, last = -1;
        while(!q.empty()){
            int v = q.front().first, s = q.front().second;
            q.pop_front();
            if (last != -1 && last != u[v][s].first) break;
            if (v == n){
                last = u[v][s].first;
                kek = u[v][s].second;
                continue;
            }
            for (auto to : g[s][v]){
                if (make_pair(u[v][s].first, u[v][s].second + 1) < u[to][s]){
                    u[to][s] = {u[v][s].first, u[v][s].second + 1};
                    q.push_front({to, s});
                }
            }
            if (make_pair(u[v][s].first + 1, u[v][s].second) < u[v][s ^ 1]){
                u[v][s ^ 1] = {u[v][s].first + 1, u[v][s].second};
                q.pb({v, s ^ 1});
            }
        }
        int now = 1;
        for (int j = 0; j < last; j++){
            now *= 2;
            now %= MOD;
        }
        cout << (now - 1 + kek + MOD) % MOD << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}