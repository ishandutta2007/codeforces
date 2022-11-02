#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++){
            cnt++;
            if (cnt * a[i] >= x){
                ans++;
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}