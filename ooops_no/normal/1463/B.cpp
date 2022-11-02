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
        for (int i = 0; i < n; i++){
            cin >> v[i];
            int now = 1, kek = -1e18;
            for (int j = 0; j < 40; j++){
                if (now > 1e9) break;
                if (abs(v[i] - now) < abs(v[i] - kek)){
                    kek = now;
                }
                now *= 2;
            }
            cout << kek << " ";
        }
        cout << endl;
    }
    return 0;
}