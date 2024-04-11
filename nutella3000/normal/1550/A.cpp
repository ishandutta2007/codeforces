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
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

void run() {
    int s;
    cin >> s;
    for (int k = 1, sum = 0; k <= s + 100; k += 2) {
        sum += k;
        if (sum >= s) {
            cout << k / 2 + 1 << endl;
            return;
        }
    }
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