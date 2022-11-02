#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

map<int,int> mp;

void solve(vector<pair<int,int>> a, int m){
    deque<pair<int,int>> q;
    for (int i = 0; i < a.size(); i++){
        if (a[i].second == 1 && q.size() > 0 && q.back().second == 0){
            mp[q.back().first] = mp[a[i].first] = abs(a[i].first - q.back().first) / 2;
            q.pop_back();
        }
        else q.pb({a[i].first, a[i].second});
    }
    vector<int> b, c;
    for (auto to : a){
        if (mp[to.first] == -1){
            if (to.second == 0){
                b.pb(to.first);
            }
            else{
                c.pb(to.first);
            }
        }
    }
    sort(b.begin(), b.end());
    while(b.size() > 1){
        int i = b.back();
        b.pop_back();
        int j = b.back();
        b.pop_back();
        mp[i] = mp[j] = m - max(i, j) + (max(i, j) - min(i, j)) / 2;
    }
    sort(c.rbegin(), c.rend());
    while(c.size() > 1){
        int i = c.back();
        c.pop_back();
        int j = c.back();
        c.pop_back();
        mp[i] = mp[j] = min(i, j) + (max(i, j) - min(i, j)) / 2;
    }
    if (c.size() && b.size()){
        int i = c[0], j = b[0];
        int t = max(i, m - j);
        t += abs((t - i) - (2 * m - t - j)) / 2;
        mp[i] = mp[j] = t;
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> a, b;
        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++){
            cin >> x[i];
            mp[x[i]] = -1;
        }
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            if (c == 'L') t[i] = 1;
            else t[i] = 0;
        }
        for (int i = 0; i < n; i++){
            if (x[i] % 2 == 0){
                a.pb({x[i], t[i]});
            }
            else{
                b.pb({x[i], t[i]});
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        solve(a, m);
        solve(b, m);
        for (auto to : x){
            cout << mp[to] << ' ';
        }
        cout << endl;
    }
    return 0;
}