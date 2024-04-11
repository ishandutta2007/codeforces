#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 2e9 + 3;
const int max_n = 2e6 + 3;

void run() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int mx = a + b + c - 3;
    int mn = max({a, b, c}) - min({a, b, c}) - (a + b + c - max({a, b, c}) - min({a, b, c})) - 1;
    cout << (mn <= m && mx >= m ? "YES" : "NO") << endl;
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