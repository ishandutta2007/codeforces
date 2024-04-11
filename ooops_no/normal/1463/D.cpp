#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
int t[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> st;
        for (int i = 1; i <= 2 * n; i++) st.insert(i);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            st.erase(v[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (st.lower_bound(v[i]) != st.end()){
                st.erase(*st.lower_bound(v[i]));
                ans++;
            }
        }
        st.clear();
        for (int i = 1; i <= 2 * n; i++){
            st.insert(i);
        }
        for (int i = 0; i < n; i++){
            st.erase(v[i]);
        }
        int col = n;
        for (int i = n - 1; i > -1; i--){
            while(st.size() > 0 && *st.rbegin() > v[i]){
                st.erase(*st.rbegin());
            }
            if (st.size() != 0){
                col--;
                st.erase(*st.rbegin());
            }
        }
        cout << abs(ans - col) + 1 << endl;
    }
    return 0;
}