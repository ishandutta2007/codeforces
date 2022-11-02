#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double

using namespace std;

mt19937 rnd(51);

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
        int n;
        cin >> n;
        vector<int> v(n), pr(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            pr[i] = v[i];
        }
        bool x = 0;
        for (int i = 1; i < n; i++){
            if (i % 2 == 1) pr[i] = pr[i - 1] - pr[i];
            else pr[i] = pr[i - 1] + pr[i];
            if (i % 2 == 1 && pr[i] > 0) x = 1;
            if (i % 2 == 0 && pr[i] < 0) x = 1;
        }
        if (!x && pr[n - 1] == 0){
            cout << "YES\n";
        }
        else{
            vector<int> mn(n, 1e18), mx(n, -1e18);
            for (int i = n - 1; i > -1; i--){
                if (i + 1 < n){
                    mn[i] = mn[i + 1];
                    mx[i] = mx[i + 1];
                }
                if (i % 2 == 0) mn[i] = min(mn[i], pr[i]);
                else mx[i] = max(mx[i], pr[i]);
            }
            bool x = 0;
            for (int i = 0; i < n - 1; i++){
                int sum = pr[n - 1], last = 0;
                if (i % 2 == 0) last = v[i] - v[i + 1];
                else last = v[i + 1] - v[i];
                sum -= last * 2;
                if (sum == 0){
                    if (i % 2 == 0){
                        if (pr[i] - last >= 0 && mn[i + 1] - last * 2 >= 0 && mx[i + 1] - last * 2 <= 0){
                            x = 1;
                            break;
                        }
                    }
                    else{
                        if (pr[i] - last <= 0 && mn[i + 1] - last * 2 >= 0 && mx[i + 1] - last * 2 <= 0){
                            x = 1;
                            break;
                        }
                    }
                }
                if (i % 2 == 1 && pr[i] > 0) break;
                if (i % 2 == 0 && pr[i] < 0) break;
            }
            if (x) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}