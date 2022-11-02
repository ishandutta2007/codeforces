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

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    int total_sum = 0;
    set<pair<int, pair<vector<int>,int>>> st;
    vector<int> b;
    for (int i = 0; i < n; i++){
        total_sum += a[i].back();
        b.pb((int)(a[i].size()) - 1);
    }
    st.insert({total_sum, {b, 0}});
    map<vector<int>, int> was;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        vector<int> b(n);
        for (int j = 0; j < n; j++){
            cin >> b[j];
            b[j]--;
        }
        was[b] = 1;
    }
    while(st.size() > 0){
        auto p = *st.rbegin();
        if (!was[p.second.first]){
            for (auto to : p.second.first){
                cout << to + 1 << ' ';
            }
            return 0;
        }
        st.erase(p);
        if (p.second.second + 1 < n){
            st.insert({p.first, {p.second.first, p.second.second + 1}});
        }
        if (p.second.first[p.second.second] == 0){
            continue;
        }
        p.first -= a[p.second.second][p.second.first[p.second.second]];
        p.second.first[p.second.second]--;
        p.first += a[p.second.second][p.second.first[p.second.second]];
        st.insert(p);
    }
    return 0;
}