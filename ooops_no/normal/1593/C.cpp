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
        int n, k;
        cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; i++){
            cin >> x[i];
        }
        sort(x.rbegin(), x.rend());
        int now = 0, ans = 0;
        for (int i = 0; i < k; i++){
            if (now >= x[i]) break;
            now += n - x[i];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}