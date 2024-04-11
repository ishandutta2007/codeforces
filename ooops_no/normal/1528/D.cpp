#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 610;
vector<pair<int,int>> g[N];
int d[N], dd[N];
bool used[N];
int n, m;

vector<int> func(int v){
    for (int i = 0; i < n; i++) d[i] = 2e9;
    for (int i = 0; i < n; i++) used[i] = 0;
    d[v] = 0;
    for (int _ = 0; _ < n; _++){
        int v = -1;
        for (int i = 0; i < n; i++){
            if ((v == -1 || d[i] < d[v]) && !used[i]){
                v = i;
            }
        }
        used[v] = 1;
        for (int i = 0; i < n; i++){
            dd[i] = 2e9;
        }
        for (auto to : g[v]){
            dd[(to.first + d[v]) % n] = to.second;
        }
        for (int k = 0; k < 2; k++){
            for (int i = 1; i < n; i++){
                dd[i] = min(dd[i], dd[i - 1] + 1);
            }
            dd[0] = min(dd[0], dd[n - 1] + 1);
        }
        for (int i = 0; i < n; i++){
            d[i] = min(d[i], dd[i] + d[v]);
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++) a.pb(d[i]);
    return a;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        ans.pb(func(i));
    }
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}