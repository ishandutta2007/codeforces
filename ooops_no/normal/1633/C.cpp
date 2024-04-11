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
        int hc, dc, hm, dm, k, w, a;
        bool ok = 0;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        for (int i = 0; i <= k; i++) {
            int cnt = (hc + a * i + dm - 1) / dm;
            int nw = dc + w * (k - i);
            int cntt = (hm + nw - 1) / nw;
            if (cntt <= cnt) {
                ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}