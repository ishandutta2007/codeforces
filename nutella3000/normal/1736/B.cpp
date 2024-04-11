#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    for (int i = 0; i < n; ++i) {
        if (i >= 2 && gcd(lcm(a[i], a[i-1]), lcm(a[i-2], a[i-1])) != a[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}