#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

bool near(array<int, 2> a, array<int, 2> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]) <= 1;
}

void run() {
    int n; cin >> n;
    array<int, 2> a, b, c;
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    array<int, 2> m;
    if (near(a, b) && near(a, c)) m = a;
    else if (near(b, a) && near(b, c)) m = b;
    else m = c;

    int x, y; cin >> x >> y;
    array<int, 2> fuck = {x, y};

    if ((m[0] == 1 || m[0] == n) && (m[1] == 1 || m[1] == n)) {
        cout << (fuck != a && fuck != b && fuck != c && x != m[0] && y != m[1] ? "NO" : "YES") << '\n';
        return;
    }
    cout << (abs(x - m[0]) % 2 == 1 && abs(y - m[1]) % 2 == 1 ? "NO" : "YES") << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}