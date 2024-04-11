#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int INF = 1e9;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            while (b[i] % 2 == 0) {
                b[i] /= 2;
            }
        }
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            st.insert(a);
        }
        sort(b.rbegin(), b.rend());
        bool bad = 0;
        for (auto a : b) {
            while (1) {
                auto val = *st.rbegin();
                st.erase(st.find(val));
                if (val > a) {
                    st.insert(val / 2);
                } else {
                    if (val != a) {
                        bad = 1;
                    }
                    break;
                }
            }
        }
        cout << (!bad ? "YES\n" : "NO\n");
    }
    return 0;
}