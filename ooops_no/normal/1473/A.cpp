#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        bool x = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] > d) cnt++;
            for (int j = i + 1; j < n; j++){
                if (v[i] + v[j] <= d){
                    x = 1;
                }
            }
        }
        if (x || cnt == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}