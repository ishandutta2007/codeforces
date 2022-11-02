#include<bits/stdc++.h>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(49);

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for (int j = 0; j < m; j++){
        cin >> b[j].first >> b[j].second;
    }
    int ans = 1e18, cnt = 0, mx = -1;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i].first <= b[j].first && a[i].second <= b[j].second){
                v.pb({b[j].second - a[i].second, b[j].first - a[i].first});
            }
        }
    }
    if (v.size() == 0){
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    cnt = v.back().first;
    ans = cnt + 1;
    for (int i = v.size() - 1; i >= 0; i--){
        cnt = v[i].first;
        ans = min(ans, cnt + mx + 2);
        mx = max(mx, v[i].second);
    }
    ans = min(ans, mx + 1);
    cout << ans << endl;
    return 0;
}