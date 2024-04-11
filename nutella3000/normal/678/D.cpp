#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 500;
const int mod = 1e9 + 7;

int binpow(int a, int b) {
    if (b == 0) return 1;
    if ((b & 1) == 0) return binpow(a*a % mod, b/2);
    return a * binpow(a*a % mod, b/2) % mod;
}

int inv(int a) { return binpow(a, mod - 2); }

void run() {
    int a, b, n, x; cin >> a >> b >> n >> x;
    if (a == 1) cout << (x + n % mod * b) % mod << endl;
    else {
        int c = binpow(a, n);
        cout << (x * c + b * (c - 1) % mod * inv(a - 1)) % mod << endl;
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}