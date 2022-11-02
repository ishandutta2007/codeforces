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
    int s, n;
    cin >> s >> n;
    vector<int> ans(n);
    vector<int> a;
    vector<pair<int,int>> add;
    int now = 1;
    while(now < 1e10){
        a.pb(now);
        now *= 10;
    }
    int have = 0;
    for (int i = a.size() - 1; i >= 0; i--){
        int can = s / a[i];
        while(can > 0){
            if (s - can * a[i] < max(0ll, n - have - can)){
                can--;
            }
            else break;
        }
        s -= can * a[i];
        add.pb({a[i], can});
        have += can;
    }
    now = 0;
    for (auto to : add){
        int j = 0;
        for (int i = 0; i < to.second; i++){
            if (now < n){
                ans[now++] += to.first;
            }
            else{
                ans[j++] += to.first;
                j %= n;
            }
        }
    }
    for (auto to : ans) cout << to << ' ';
    cout << endl;
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