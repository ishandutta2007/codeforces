#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int mod = 1e9 + 7;
const int max_n = 1e5 + 3;

const int inf = 2e9 + 3;

void run() {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    if (x2 - x1 + w > W && y2 - y1 + h > H) {
        cout << -1 << endl;
        return;
    }
    int t1 = max(x1, W - x2), t2 = max(y1, H - y2);
    cout << min(x2 - x1 + w > W ? inf : max(0ll, w - t1), y2 - y1 + h > H ? inf : max(0ll, h - t2)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}