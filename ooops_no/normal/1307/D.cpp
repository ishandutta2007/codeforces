#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> dn, d1;

bool cmp(const int &a, const int &b){
    return d1[a] < d1[b];
}

vector<int> bfs(int v){
    vector<int> d(N, 1e18);
    d[v] = 0;
    deque<int> q{v};
    while(q.size() > 0){
        int u = q.front();
        q.pop_front();
        for (auto to : g[u]){
            if (d[to] == 1e18){
                d[to] = d[u] + 1;
                q.pb(to);
            }
        }
    }
    return d;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dn = bfs(n), d1 = bfs(1);
    int ans = d1[n];
    vector<pair<int,int>> b;
    for (auto to : a){
        b.pb({dn[to], to});
    }
    sort(b.rbegin(), b.rend());
    vector<pair<int,int>> mx(k, pair<int,int>{-1e18, -1e18});
    for (int i = 0; i < k; i++){
        if (i > 0) mx[i] = mx[i - 1];
        if (mx[i].first == -1e18 || d1[b[i].second] > d1[mx[i].first]){
            mx[i].second = mx[i].first;
            mx[i].first = b[i].second;
        }
        else if (mx[i].second == -1e18 || d1[b[i].second] > d1[mx[i].second]){
            mx[i].second = b[i].second;
        }
    }
    sort(a.begin(), a.end(), cmp);
    int l = 0, r = 1e18;
    while(r - l > 1){
        int mid = (r + l) / 2, j = 0;
        bool x = 0;
        for (int i = 0; i < a.size(); i++){
            if (b[0].first + d1[a[i]] < mid) continue;
            while(j + 1 < b.size() && b[j + 1].first + d1[a[i]] >= mid){
                j++;
            }
            if (mx[j].first == a[i]){
                if (mx[j].second != -1e18 && d1[mx[j].second] + dn[a[i]] >= mid){
                    x = 1;
                }
            }
            else if (d1[mx[j].first] + dn[a[i]] >= mid){
                x = 1;
            }
        }
        if (x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << min(ans, l + 1) << endl;
    return 0;
}