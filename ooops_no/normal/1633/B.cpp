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
    while (t--) {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (auto to : s) {
            if (to == '0') cnt0++;
            else cnt1++;
        }
        if (cnt0 == cnt1) cout << cnt0 - 1 << endl;
        else cout << min(cnt0, cnt1) << endl;
    }
    return 0;
}