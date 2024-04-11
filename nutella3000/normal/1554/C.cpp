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

const int inf = 2e9 + 3;
//const int max_n = 4e5 + 3;

void run() {
    int n, m;
    cin >> n >> m;
    ++m;
    int res = 0;
    for (int bit = 30; bit >= 0; --bit) {
        if (m >> bit & 1) {
            if (!(n >> bit & 1)) res += (1 << bit);
        }else {
            if (n >> bit & 1) break;
        }
    }
    cout << res << endl;
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