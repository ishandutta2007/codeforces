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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

void run() {
    int n;
    cin >> n;
    int res = 0;
    int a = 1;
    for (int r = 1; r <= 100; ++r) {
        a = lcm(a, r);
        if (a > n) break;
        res += n / a;
    }
    cout << (res + n) % ((int)1e9 + 7) << endl;
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