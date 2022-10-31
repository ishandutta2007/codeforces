#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        map<int,int> cnt;
        for (int i = 0; i < 2 * k; i++){
            cnt[a[i]]++;
        }
        for (int i = 2 * k; i < n; i++) ans += a[i];
        for (auto to : cnt){
            if (to.second > k){
                ans += to.second - k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}