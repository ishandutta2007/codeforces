#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.rbegin(), a.rend());
        multiset<int> st{sum};
        bool bad = 0;
        for (int j = 0; j < n; j++) {
            while (1) {
                auto val = *st.rbegin();
                if (val > a[j]) {
                    st.erase(st.find(val));
                    st.insert(val / 2);
                    st.insert((val + 1) / 2);
                } else if (val < a[j]) {
                    bad = 1;
                    break;
                } else if (val == a[j]) {
                    st.erase(st.find(val));
                    break;
                }
            }
            if (bad) break;
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
    return 0;
}