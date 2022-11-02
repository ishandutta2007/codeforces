#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n, add = 0;
        cin >> n;
        vector<int> a(n);
        multiset<int> st;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }
        int ans = *min_element(a.begin(), a.end());
        while(st.size() > 1){
            ans = max(ans, *st.begin() - add);
            add += (*st.begin() - add);
            st.erase(st.find(*st.begin()));
        }
        ans = max(ans, *st.begin() - add);
        cout << ans << endl;
    }
    return 0;
}