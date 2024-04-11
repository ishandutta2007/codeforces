#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    vector<pair<int,int>> u(k);
    set<int> used_x, used_y;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        used_x.insert(x[i]);
    }
    for (int i = 0; i < m; i++){
        cin >> y[i];
        used_y.insert(y[i]);
    }
    vector<int> xx, yy;
    map<int, vector<int>> mp, mpp;
    for (int i = 0; i < k; i++){
        cin >> u[i].first >> u[i].second;
        if (used_x.find(u[i].first) != used_x.end() && used_y.find(u[i].second) != used_y.end()){
            continue;
        }
        else if (used_x.find(u[i].first) != used_x.end()){
            yy.pb(u[i].second);
            mp[u[i].first].pb(u[i].second);
        }
        else{
            xx.pb(u[i].first);
            mpp[u[i].second].pb(u[i].first);
        }
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    int r = 0, ans = 0;
    for (int i = 0; i < yy.size(); i++){
        while(r + 1 < yy.size() && (*used_y.lower_bound(yy[i]) > yy[r + 1])){
            r++;
        }
        ans += r - i;
    }
    r = 0;
    for (int i = 0; i < xx.size(); i++){
        while(r + 1 < xx.size() && (*used_x.lower_bound(xx[i]) > xx[r + 1])){
            r++;
        }
        ans += r - i;
    }
    for (auto to : mp){
        int r = 0;
        sort(to.second.begin(), to.second.end());
        for (int i = 0; i < to.second.size(); i++){
            while(r + 1 < to.second.size() && (*used_y.lower_bound(to.second[i]) > to.second[r + 1])){
                r++;
            }
            ans -= r - i;
        }
    }
    for (auto to : mpp){
        int r = 0;
        sort(to.second.begin(), to.second.end());
        for (int i = 0; i < to.second.size(); i++){
            while(r + 1 < to.second.size() && (*used_x.lower_bound(to.second[i]) > to.second[r + 1])){
                r++;
            }
            ans -= r - i;
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}