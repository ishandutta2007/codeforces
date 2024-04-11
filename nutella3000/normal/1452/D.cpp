#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e15;
const int max_n = 2e5 + 2;
const int mod = 998244353;


int dp[max_n];


int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int inv(int a) {
    return binpow(a, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> s(2);
    s[0] = inv(2);
    s[1] = inv(2);

    dp[1] = inv(2);
    
    for(int i = 2;i <= n;i++) {
        s[0] = s[0] * inv(2) % mod;
        s[1] = s[1] * inv(2) % mod;
        dp[i] = s[1 - i % 2];
        s[i % 2] = (s[i % 2] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}