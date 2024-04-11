#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c(n * k);
    vector<vector<int>> ind(n);
    vector<bool> used(n);
    vector<pair<int,int>> ans(n);
    for (int i = 0; i < n * k; i++){
        cin >> c[i];
        c[i]--;
        ind[c[i]].pb(i);
    }
    for (int i = 0; i < k - 1; i++){
        vector<pair<int,int>> a;
        for (int j = 0; j < n; j++){
            a.pb({ind[j][i + 1], j});
        }
        sort(a.begin(), a.end());
        int can = (n + k - 2) / (k - 1);
        for (auto to : a){
            if (used[to.second] || !can) continue;
            can--;
            used[to.second] = 1;
            ans[to.second] = {ind[to.second][i], ind[to.second][i + 1]};
        }
    }
    for (auto to : ans){
        cout << to.first + 1 << ' ' << to.second + 1 << endl;
    }
    return 0;
}