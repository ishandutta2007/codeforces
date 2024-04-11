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

void run() {
    int h, n; cin >> h >> n; --n;

    int cnt = 0, v = 0, vh = 0, op = 0;

    while (vh != h || v != n) {
        if ((n >> (h-vh)) != v) {
            cnt += (1ll << (1 + h-vh)) - 1;
            op = v&1;
            v ^= 1;
            continue;
        }
        ++cnt;
        v = v * 2 + op, vh++;
        op = 1 - op;
    }
    cout << cnt << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}