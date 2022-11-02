#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int now = 1, ans = 0;
        for (int i = 0; i < 30; i++){
            if (k & (1 << i)){
                ans = (ans + now) % MOD;
            }
            now = (now * n) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}