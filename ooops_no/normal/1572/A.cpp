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
    int n, cnt = 0;
    cin >> n;
    set<int> st;
    vector<vector<int>> g(n);
    vector<int> need(n);
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        if (m == 0) st.insert(i);
        need[i] = m;
        for (int j = 0; j < m; j++){
            int a;
            cin >> a;
            a--;
            g[a].pb(i);
        }
    }
    int last = -1, ans = 1;
    while(1){
        if (st.size() == 0) break;
        if (st.lower_bound(last) == st.end()){
            last = *st.begin();
            ans++;
            continue;
        }
        cnt++;
        int v = *st.lower_bound(last);
        for (auto to : g[v]){
            need[to]--;
            if (need[to] == 0) st.insert(to);
        }
        st.erase(v);
        last = v;
    }
    if (cnt != n){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
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