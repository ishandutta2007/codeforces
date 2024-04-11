#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                st.insert(v[j] - v[i]);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}