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
 
const int inf = 1e15 + 3, mod = 998244353;
const int max_n = 1e5 + 3;

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int f(vector<int> a, int st) {
    int n = size(a);
    vector<int> dp(n + 1), dp1(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        dp1 = dp;
        for (int j = 0; j < n; ++j) {
            int toj = j + a[i];
            if (toj >= 0) dp1[toj] = (dp1[toj] + dp[j]) % mod;
            if (i < st && toj == -1) dp1[j] = (dp1[j] + dp[j]) % mod;
        }
        swap(dp, dp1);
    }
    int res = 0;
    for (int i = 0; i <= n; ++i)
        res += dp[i];
    return res % mod;
}

void run() {
    int n;
    cin >> n;
    vector<pii> req(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "-") req[i] = {-1, 0};
        else {
            req[i].fi = 1;
            cin >> req[i].se;
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (req[i].fi == -1) continue;

        vector<int> br;
        int st = 0;
        for (int j = 0; j < n; ++j) {
            if (j == i) st = size(br);
            if (req[j].fi == -1) br.pb(-1);
            else {
                if (req[j].se < req[i].se || (req[j].se == req[i].se && j < i)) br.pb(1);
            }
        }
        /*for (auto q : br)
            cout << q << " ";
        cout << endl;*/
        //cout << i + 1 << " " << f(br, st) << endl;
        res += f(br, st) * req[i].se % mod * binpow(2, n - 1 - size(br)) % mod;
    }
    cout << res % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}