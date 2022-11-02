#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(_v) _v.begin(), _v.end()
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        cout << (((a + b + c + n) % 3 == 0 && n >= 3 * max(a, max(b, c)) - (a + b + c)) ? "YES" : "NO") << endl;
    }
}