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

const int N = 1e6 + 10;
vector<pair<int,int>> add[N], del[N];
multiset<int> st[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++){
        int l;
        cin >> l;
        for (int j = 0; j < l; j++){
            int a;
            cin >> a;
            add[j].pb({a, i});
            del[j + w - l].pb({a, i});
        }
        if (l < w){
            add[l].pb({0, i});
            del[w - 1].pb({0, i});
            add[0].pb({0, i});
            del[w - l - 1].pb({0, i});
        }
    }
    int ans = 0;
    for (int i = 0; i < w; i++){
        for (auto to : add[i]){
            ans -= (st[to.second].size() == 0 ? 0 : *st[to.second].rbegin());
            st[to.second].insert(to.first);
            ans += (st[to.second].size() == 0 ? 0 : *st[to.second].rbegin());
        }
        cout << ans << ' ';
        for (auto to : del[i]){
            ans -= (st[to.second].size() == 0 ? 0 : *st[to.second].rbegin());
            st[to.second].erase(st[to.second].find(to.first));
            ans += (st[to.second].size() == 0 ? 0 : *st[to.second].rbegin());
        }
    }
    return 0;
}