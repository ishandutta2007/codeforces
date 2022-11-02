#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

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
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        a.pb(2 * INF);
        int l = 0, r = INF + 1;
        while(r - l > 1){
            int mid = (r + l) / 2, ans = 0;
            for (int i = 0; i < n; i++){
                ans = min(INF, ans + min(a[i + 1] - a[i], mid));
            }
            if (ans >= h) r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
    return 0;
}