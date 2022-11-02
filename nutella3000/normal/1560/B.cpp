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
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3;
const int max_n = 1e5 + 3;

int f(string s, string t) {
    int id = 0;
    for (int i = 0; i < size(s); ++i) {
        if (id < size(t) && t[id] == s[i]) ++id;
    }
    return (size(s) - id) + size(t) - id;
}

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = abs(b - a);
    if (a > b) swap(a, b);
    if (a > n || b <= n || c > 2 * n) cout << -1 << endl;
    else cout << (c <= n ? c + n : c - n) << endl;
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