#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int now = a[0], x = 0;
        for (int i = 1; i < n; i++){
            if (abs(a[i] - now) > 1){
                x = 1;
                break;
            }
            now = a[i];
        }
        if (x){
            cout << 0 << endl;
        }
        else{
            set<int> st;
            for (auto to : a) st.insert(to);
            if (st.size() == 1){
                cout << min(v * 2, u + v) << endl;
            }
            else{
                cout << min(u, v) << endl;
            }
        }
    }
    return 0;
}