#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const ll infL = 1e18 + 7;

void run() {
    int n, m, x, y, d; cin >> n >> m >> x >> y >> d; --x, --y;
    if ((x-d <= 0 || y+d >= m-1) && (x+d >= n-1 || y-d <= 0)) cout << -1 << '\n';
    else cout << n+m-2 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}