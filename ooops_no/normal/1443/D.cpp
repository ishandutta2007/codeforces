#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long


signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int mn = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        for (int i = 1; i < n; i++){
            v[i] -= mn;
            if (v[i] > v[i - 1]){
                mn += v[i] - v[i - 1];
                v[i] = v[i - 1];
            }
        }
        bool x = 0;
        for (auto to : v){
            x |= to < 0;
        }
        if (x){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}