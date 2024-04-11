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
const int max_n = 2e5 + 3, log_n = 20;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool run() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    map<int, int> two[2];
    for (int i = 0; i < n; ++i)
        ++two[i % 2][b[i]];
    for (int i = 0; i < n; ++i)
        --two[i % 2][a[i]];
    for (int i = 0; i < 2; ++i)
        for (auto j : two[i])
            if (j.se != 0) return false;

    return true;
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
        cout << (run() ? "YES" : "NO") << endl;
    }
}