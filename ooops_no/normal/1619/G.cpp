#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n), t(n);
        vector<bool> used(n);
        map<int, set<pair<int,int>>> x_set, y_set;
        for (int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> t[i];
            x_set[x[i]].insert({-INF, -1});
            x_set[x[i]].insert({INF, -1});
            x_set[x[i]].insert({y[i], i});
            y_set[y[i]].insert({x[i], i});
            y_set[y[i]].insert({-INF, -1});
            y_set[y[i]].insert({INF, -1});
        }
        vector<int> arr;
        for (int i = 0; i < n; i++){
            if (!used[i]){
                int timer = t[i];
                deque<int> q{i};
                used[i] = 1;
                while(q.size() > 0){
                    int v = q.front();
                    q.pop_front();
                    timer = min(timer, t[v]);
                    x_set[x[v]].erase({y[v], v});
                    y_set[y[v]].erase({x[v], v});
                    auto it = x_set[x[v]].lower_bound({y[v], -1});
                    if (abs(it->first - y[v]) <= k){
                        if (!used[it->second]){
                            used[it->second] = 1;
                            q.pb(it->second);
                        }
                    }
                    it--;
                    if (abs(it->first - y[v]) <= k){
                        if (!used[it->second]){
                            used[it->second] = 1;
                            q.pb(it->second);
                        }
                    }
                    auto itt = y_set[y[v]].lower_bound({x[v], -1});
                    if (abs(itt->first - x[v]) <= k){
                        if (!used[itt->second]){
                            used[itt->second] = 1;
                            q.pb(itt->second);
                        }
                    }
                    itt--;
                    if (abs(itt->first - x[v]) <= k){
                        if (!used[itt->second]){
                            used[itt->second] = 1;
                            q.pb(itt->second);
                        }
                    }
                }
                arr.pb(timer);
            }
        }
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){
            ans = max(ans, min(i, arr[i]));
        }
        cout << ans << endl;
    }
    return 0;
}