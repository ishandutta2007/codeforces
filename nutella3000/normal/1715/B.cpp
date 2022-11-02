#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
 
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;
const int mod = 998244353;

void run() {
    ll n, k, b, s; cin >> n >> k >> b >> s;
    if (s > b * k + n * (k-1) || s < b * k) {
        cout << -1 << '\n';
    } else {
        s -= b * k;
        for (int i = 0; i < n-1; ++i) {
            cout << min(s, k-1) << " ";
            s -= min(s, k-1);
        }
        cout << b * k + s << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}