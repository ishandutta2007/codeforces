#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans;
        set<int> st;
        for (int i = 1; i <= n; i++){
            st.insert(i);
        }
        ans.pb(a);
        st.erase(a);
        while(ans.size() < n / 2){
            if (*st.rbegin() == b){
                st.erase(b);
                continue;
            }
            if (*st.rbegin() < a){
                break;
            }
            ans.pb(*st.rbegin());
            st.erase(ans.back());
        }
        if (ans.size() < n / 2){
            cout << -1 << endl;
            continue;
        }
        st.insert(b);
        for (auto to : st) ans.pb(to);
        if (*st.rbegin() == b){
            for (auto to : ans){
                cout << to << ' ';
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}