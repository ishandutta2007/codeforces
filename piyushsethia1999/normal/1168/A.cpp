#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    int s = 0, e = m - 1;
    while (s < e) {
        int mi = (s + e) >> 1;
        int mii = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int l = (a[i]), r = (a[i] + mi) % m;
            if (l <= r) {
                if (l <= mii && mii <= r) {

                } else if(mii < l) {
                    mii = l;
                } else {
                    ok = false;
                }
            } else {
                if (mii <= r) {

                } else if(mii >= l) {

                } else {
                    mii = l;
                }
            }
        }
        if (ok) {
            e = mi;
        } else {
            s = mi + 1;
        }
    } 
    cout << s;
}