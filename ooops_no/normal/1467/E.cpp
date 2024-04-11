#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ld long double

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> a(N);
vector<int> d(N);
vector<int> g[N];
vector<int> lll(N);
vector<vector<int>> need(N);
vector<bool> used(N);
vector<int> col(N);
vector<int> type(N);
vector<int> u;
int po[21][N], n, ans = 0, m;

void zhfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            po[0][to] = v;
            d[to] = d[v] + 1;
            zhfs(to, v);
        }
    }
}

void check(int v, int sum, int p){
    int j = lower_bound(u.begin(), u.end(), a[v]) - u.begin();
    col[j]++;
    if (type[j] == 1){
        if (col[j] > 1) {
            cout << 0;
            exit(0);
        }
    }
    else{
        if (col[j] > 2){
            cout << 0;
            exit(0);
        }
    }
    for (auto to : g[v]){
        if (to != p){
            check(to, sum, v);
        }
    }
    col[j]--;
}

int lca(int a, int b){
    if (d[a] < d[b]) swap(a, b);
    for (int i = 20; i >= 0; i--){
        if ((d[a] - (1 << i)) >= d[b]){
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 20; i >= 0; i--){
        if (po[i][a] != po[i][b]){
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

void find_ans(int v, int sum, int p){
    sum += lll[v];
    if (sum == m) ans++;
    for (auto to : g[v]){
        if (to != p){
            find_ans(to, sum, v);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        u.pb(a[i]);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 1; i <= n; i++){
        int j = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
        need[j].pb(i);
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    zhfs(1, -1);
    po[0][1] = 1;
    for (int i = 1; i <= 20; i++){
        for (int j = 1; j <= n; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < N; i++){
        if (need[i].size() <= 2) continue;
        for (auto to : need[i]) used[to] = 1;
        int l = lca(need[i][0], need[i][1]);
        for (int j = 2; j < need[i].size(); j++){
            l = lca(l, need[i][j]);
        }
        if (used[l]){
            set<int> st;
            for (auto to : need[i]){
                if (to == l) continue;
                for (int i = 20; i >= 0; i--){
                    if ((d[to] - (1 << i)) > d[l]){
                        to = po[i][to];
                    }
                }
                st.insert(to);
            }
            if (st.size() > 1){
                cout << 0;
                return 0;
            }
            type[i] = 2;
        }
        else{
            type[i] = 1;
        }
        for (auto to : need[i]) used[to] = 0;
    }
    check(1, 0, -1);
    for (int i = 0; i < N; i++){
        if (need[i].size() == 0) continue;
        if (need[i].size() == 1){
            lll[1]++;
            continue;
        }
        for (auto to : need[i]) used[to] = 1;
        int l = lca(need[i][0], need[i][1]);
        for (int j = 2; j < need[i].size(); j++){
            l = lca(l, need[i][j]);
        }
        if (used[l]){
            set<int> st;
            for (auto to : need[i]){
                if (to == l) continue;
                for (int i = 20; i >= 0; i--){
                    if ((d[to] - (1 << i)) > d[l]){
                        to = po[i][to];
                    }
                }
                st.insert(to);
            }
            lll[*st.begin()]++;
            for (auto to : need[i]){
                if (to != l) lll[to]--;
            }
        }
        else{
            lll[1]++;
            for (auto to : need[i]){
                lll[to]--;
            }
        }
        for (auto to : need[i]) used[to] = 0;
    }
    m = u.size();
    find_ans(1, 0, -1);
    cout << ans << endl;
    return 0;
}