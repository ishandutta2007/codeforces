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
    int t;
    cin >> t;
    int now = 2050;
    vector<int> a;
    while (1){
        a.pb(now);
        if (now >= 1e18) break;
        now *= 10;
    }
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = a.size() - 1; i >= 0; i--){
            while(n >= a[i]){
                n -= a[i];
                cnt++;
            }
        }
        if (n != 0) cout << -1 << endl;
        else cout << cnt << endl;
    }
    return 0;
}