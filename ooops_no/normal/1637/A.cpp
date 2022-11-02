#include<bits/stdc++.h>

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
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        bool x = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > *st.begin()) {
                x = 1;
            }
            st.erase(st.find(a[i]));
        }
        cout << (x ? "YES\n" : "NO\n");
    }
    return 0;
}