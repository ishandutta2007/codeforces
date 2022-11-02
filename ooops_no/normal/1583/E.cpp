#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 6e5 + 10;
vector<int> g[N];
vector<pair<int,int>> gr[N];
vector<bool> used(N);
vector<pair<int,int>> ans;
int n, m;

void dfs(int v, int pr){
    for (auto to : gr[v]){
        if (!used[to.second]){
            used[to.second] = 1;
            dfs(to.first, to.second);
        }
    }
    ans.pb({v, pr});
}

vector<int> go(int a, int b){
    vector<int> par(n, -1), ans;
    par[a] = a;
    deque<int> q{a};
    while(q.size() > 0){
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]){
            if (par[to] == -1){
                par[to] = v;
                q.pb(to);
            }
        }
    }
    while(b != a){
        ans.pb(b);
        b = par[b];
    }
    ans.pb(a);
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int q;
    cin >> q;
    vector<vector<int>> show(q);
    vector<pair<int,int>> u(q);
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        u[i] = {x, y};
        gr[x].pb({y, i});
        gr[y].pb({x, i});
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if ((int)(gr[i].size()) & 1){
            cnt++;
        }
    }
    if (cnt > 0){
        cout << "NO\n" << cnt / 2 << endl;
    }
    else{
        for (int i = 0; i < n; i++){
            ans.clear();
            dfs(i, -1);
            if (ans.size() == 1) continue;
            reverse(ans.begin(), ans.end());
            vector<int> last;
            for (int j = 1; j < ans.size(); j++){
                auto kek = go(ans[j - 1].first, ans[j].first);
                if (ans[j].first == ans[0].first){
                    show[ans[j].second] = last;
                    last.clear();
                    continue;
                }
                if (last.size() == 0){
                    last = kek;
                    show[ans[j].second] = last;
                }
                else{
                    map<int,int> was;
                    for (auto to : last) was[to] = 1;
                    vector<int> nw;
                    for (int i = (int)(kek.size()) - 1; i >= 0; i--){
                        if (was[kek[i]]){
                            while(1){
                                nw.pb(last.back());
                                if (last.back() == kek[i]){
                                    break;
                                }
                                last.pop_back();
                            }
                            for (int j = i + 1; j < kek.size(); j++){
                                nw.pb(kek[j]);
                                last.pb(kek[j]);
                            }
                            break;
                        }
                    }
                    show[ans[j].second] = nw;
                }
            }
        }
        cout << "YES\n";
        for (int i = 0; i < q; i++){
            if (show[i][0] != u[i].first){
                reverse(show[i].begin(), show[i].end());
            }
            cout << show[i].size() << endl;
            for (auto to : show[i]){
                cout << to + 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}