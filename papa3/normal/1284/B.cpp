#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

vector<int> m, d;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int dobre = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        int mi = INF;
        int ma = -INF;
        bool czy = false;
        for (int a, j = 1; j <= l; j++) {
            cin >> a;
            if (a > mi) {
                czy = true;
            }
            mi = min(mi, a);
            ma = max(ma, a);
        }
        if (czy) {
            dobre++;
        } else {
            m.push_back(mi);
            d.push_back(ma);
            if (mi < ma) {
                //res--;
            }
        }
    }
    //cout << res << endl;
    res += n * dobre * 2 - dobre * dobre;
    //cout << res << endl;
    n -= dobre;
    sort(m.begin(), m.end());
    sort(d.begin(), d.end());
    
    int gdzie = 0;
    for (int i : m) {
        while (gdzie < d.size() && d[gdzie] <= i) {
            //cout << d[gdzie] << endl;
            gdzie++;
        }
        res += d.size() - gdzie;
        //cout << i << " " << d.size() - gdzie << endl;
    }
    
    cout << res;
    
    return 0;
}