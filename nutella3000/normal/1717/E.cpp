#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(int a, int b) {
    int g = gcd(a, b);
    return (ll)a / g * b;
}

void run() {
    int n; cin >> n;
    ll res = 0;
    vector<int> phi(n+1, 1);
    phi[1] = 0;
    for (int k = 2; k < n; ++k) {
        vector<int> del;
        int v = k;
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                del.emplace_back(i);
                if (i * i != k) del.emplace_back(k / i);

                if (v % i == 0 && i != 1) {
                    phi[k] *= i-1;
                    v /= i;
                    while (v % i == 0)
                        v /= i, phi[k] *= i;
                }
            }
        }
        if (v != 1) phi[k] *= v-1;
        map<int, ll> cnt;
        for (auto g : del) {
            res += lcm(n-k, g) % mod * phi[k/g] % mod;
        }
    }
    cout << res % mod << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}