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
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<pair<int,int>> v(t);
    for (int i = 0; i < t; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int now = 0, sz = 1;
    vector<pair<int,int>> ans(v.size());
    for (int i = 0; i < v.size(); i++){
        while(now + 2 * sz - 1 < v[i].first){
            now += 2 * sz - 1;
            sz++;
        }
        if (now + sz >= v[i].first){
            ans[v[i].second] = {v[i].first - now, sz};
        }
        else{
            ans[v[i].second] = {sz, sz - (v[i].first - (now + sz))};
        }
    }
    for (auto to : ans){
        cout << to.first << ' ' << to.second << endl;
    }
    return 0;
}