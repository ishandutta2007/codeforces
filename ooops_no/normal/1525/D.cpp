#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(n * 2, 1e18);
    dp[n] = 1;
    for (int i = 0; i < n; i++){
        vector<int> dpp(n * 2, 1e18);
        for (int j = 0; j < 2 * n; j++){
            if (a[i] == 0){
                if (j - 1 >= 0){
                    dpp[j] = min(dpp[j], dp[j]);
                }
                int val = dp[j];
                if (j < n) val += i;
                else val -= i;
                if (j + 1 >= dpp.size()) continue;
                dpp[j + 1] = min(dpp[j + 1], val);
            }
            else if (j - 1 >= 0) {
                int val = dp[j];
                if (j > n) val += i;
                else val -= i;
                dpp[j - 1] = min(dpp[j - 1], val);
            }
        }
        dp = dpp;
    }
    cout << dp[n] - 1 << endl;
    return 0;
}