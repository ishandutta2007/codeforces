#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n, m;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    int prevd = 0, prevh = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int d, h;
        cin >> d >> h;
        if (i == 0) {
            ans = max(ans, d - 1 + h);
        } else {
            if (d - prevd < abs(h - prevh)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            int tmp = d - prevd - abs(h - prevh);
            ans = max(ans, max(h, prevh) + tmp / 2);
        }
        prevd = d;
        prevh = h;
    }
    ans = max(ans, prevh + n - prevd);

    cout << ans << endl;

    return 0;
}