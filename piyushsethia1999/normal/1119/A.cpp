#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    int di = (a[0] == a[1] ? 0 : 1);
    int ma = 0;
    int ca = a[0];
    int ma1 = -1;
    int ca1 = -1;
    for (int i = 1; i < n; ++i) {
        if (ca != a[i]) {
            di = max(di, i);
            if (ca1 == -1) {
                ca1 = a[i];
                ma1 = i;
            } 
        } else {
            if (ca != -1) {
                di = max(di, i - ma1);
            } 
        }
    }
    cout << di;
}