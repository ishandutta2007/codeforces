#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }

mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7, mod = 998244353;
const int N = 1e7 + 3, K = 18, L = 720720;

int n, k;
int a[N];
int dp[K][L];

int bp(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

void run() {
    int x, y, M;
    cin >> n >> a[0] >> x >> y >> k >> M;
    for (int i = 1; i < n; ++i)
        a[i] = (a[i-1]*x+y) % M;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        ++dp[0][a[i]%L];
        res = (res + (a[i]/L) * k * bp(n, k-1) % mod * L % mod) % mod;
    }
    for (int i = 0; i < k; ++i) {
        int val = bp(n, k-i-1);
        for (int j = 0; j < L; ++j) {
            dp[i][j] %= mod;
            res = (res + dp[i][j] * j % mod * val % mod) % mod;

            if (i < k-1) {
                dp[i+1][j-j%(i+1)] += dp[i][j];
                dp[i+1][j] += (n-1)*dp[i][j]%mod;
            }
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}