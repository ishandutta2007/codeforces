#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;
 
int S(int num) {
    int res = 0;
    while(num) {
        res += num % 10;
        num /= 10;
    }
    return res;
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);
 
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        int res = 0, pw = 1;
        while(S(n) > s) {
            res += pw * (10 - (n / pw % 10));
            n = (n / pw / 10 + 1) * pw * 10;
            pw *= 10;
        }
        cout << res << endl;
    }
}