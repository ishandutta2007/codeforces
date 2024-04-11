#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
vector<int> g[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear();
        vector<int> w(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            sum += w[i];
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<pair<int,int>> add;
        for (int i = 1; i <= n; i++){
            add.pb({w[i], g[i].size() - 1});
        }
        sort(add.rbegin(), add.rend());
        cout << sum << " ";
        for (int j = 0; j < add.size(); j++){
            while(add[j].second > 0){
                sum += add[j].first;
                cout << sum << " ";
                add[j].second--;
            }
        }
        cout << endl;
    }
    return 0;
}