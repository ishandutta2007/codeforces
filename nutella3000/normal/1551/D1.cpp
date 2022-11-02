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
const int max_n = 4e5 + 3;

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    bool sw = false;
    if (n % 2 == 1) {
        sw = true;
        swap(n, m);
        k = n * m / 2 - k;
    }

    if (k % 2 == 0 && 2 * k <= (m / 2 * 2) * n) cout << "YES" << endl;
    else cout << "NO" << endl;
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