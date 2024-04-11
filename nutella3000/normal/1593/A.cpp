#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);


const int inf = 1e9 + 7;


void run() {
    int a, b, c;
    cin >> a >> b >> c;
    int q = max({a, b, c});
    cout << max(0ll, max(b, c) - a + 1) << " " << max(0ll, max(a, c) - b + 1) << " " << max(0ll, max(b, a) - c + 1) << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}