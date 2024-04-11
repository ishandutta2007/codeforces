#include<bits/stdc++.h>

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
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        set<pair<int,int>> st;
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] > 0) st.insert({a[i], i});
        }
        while(st.size() > 1){
            auto p = *st.rbegin();
            st.erase(p);
            auto pp = *st.rbegin();
            st.erase(pp);
            p.first--, pp.first--;
            ans.pb({p.second, pp.second});
            if (p.first > 0) st.insert(p);
            if (pp.first > 0) st.insert(pp);
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to.first + 1 << ' ' << to.second + 1 << endl;
        }
    }
    return 0;
}