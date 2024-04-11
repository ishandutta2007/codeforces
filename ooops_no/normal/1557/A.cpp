#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

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
        int n;
        cin >> n;
        vector<int> a(n);
        ld anss = -1e18, sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum2 += a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++){
            sum2 -= a[i];
            sum1 += a[i];
            anss = max(anss, (sum1 / (ld)(i + 1)) + (sum2 / (ld)(n - i - 1)));
        }
        cout << setprecision(30) << fixed << anss << endl;
    }
    return 0;
}